#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <limits.h>

struct node{
  int data;
  struct node* left;
  struct node* right;
};

struct node* newNode(int data){
  struct node* myNode = malloc(sizeof(struct node));
  myNode->data = data;
  myNode->left = NULL;
  myNode->right = NULL;
  return myNode;
}

struct node* insert(struct node* node, int data){
  if(!node)
    return newNode(data);
  if(data <= node->data)
    node->left = insert(node->left, data);
  else
    node->right = insert(node->right, data);
  return node;
}

struct node* build123(){
  struct node* myNode = NULL;
  myNode = insert(myNode, 2);
  myNode = insert(myNode, 1);
  myNode = insert(myNode, 3);
  return myNode;
}

int size(struct node* root){
  if(!root)
    return 0;
  else
    return 1 + size(root->left) + size(root->right);
}

int maxDepth(struct node* root){
  if(!root)
    return 0;
  else{
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + (l>r? l:r);
  }
}

int minValue(struct node* root){
  assert(root);
  if(!root->left)
    return root->data;
  return minValue(root->left);
}

int maxValue(struct node* root){
  assert(root);
  if(!root->right)
    return root->data;
  return maxValue(root->right);
}

void printTree(struct node* root){
  if(!root)
    return;
  printTree(root->left);
  printf("%d ", root->data);
  printTree(root->right);
}

void printPostorder(struct node* root){
  if(!root)
    return;
  printPostorder(root->left);
  printPostorder(root->right);
  printf("%d ", root->data);
}

int hasPathSum(struct node* root, int sum){
  if(!root){
    if(sum == 0)
      return 1;
    else
      return 0;
  }
  else
    return hasPathSum(root->left, sum - root->data) || hasPathSum(root->right, sum - root->data);
}

void printArr(int arr[], int len){
  for(int i=0; i<len; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
void printPathsRecur(struct node* node, int path[], int len){
  if(!node)
    return;
  path[len] = node->data;
  if(!node->left && !node->right)
    printArr(path, len+1);
  else{
    printPathsRecur(node->left, path, len+1);
    printPathsRecur(node->right, path, len+1);
  }
}
void printPaths(struct node* node){
  int path[256];
  printPathsRecur(node, path, 0);
}

void mirror(struct node* node){
  if(!node)
    return;
  struct node* aux;
  mirror(node->left);
  mirror(node->right);
  aux = node->left;
  node->left = node->right;
  node->right = aux;
}

void doubleTree(struct node* node){
  if(!node)
    return;
  doubleTree(node->left);
  struct node* new = newNode(node->data);
  new->left = node->left;
  node->left = new;
  doubleTree(node->right);
}

int sameTree(struct node* a, struct node* b){
  if(!a || !b){
    if(!a && !b)
      return 1;
    return 0;
  }
  return sameTree(a->left, b->left) && sameTree(a->right, b->right);
}

int countDumies(int numkeys){
  if(!numkeys)
    return 1;
  int count = 0;
  int i = numkeys;
  numkeys--;
  while(i--)
    count += countDumies(i) * countDumies(numkeys-i);
  return count;
}

int countTrees(int numkeys){
  if(!numkeys)
    return 1;
  int count = 0;
  int i = 0;
  int fin;
  numkeys--;
  if(numkeys%2 == 1)
    fin = (numkeys+1)/2;
  else{
    fin = numkeys/2;
    i = countTrees(fin);
    count += i*i;
  }
  for(i=0; i<fin; i++)
    count += 2 * countTrees(i) * countTrees(numkeys-i);
  return count;
}

int isBST1(struct node* node){
  if(!node)
    return 1;
  int mid = 1;
  if(node->left)
    mid *= (maxValue(node->left) <= node->data); //mid &= max(left) <= data 
  if(node->right)
    mid *= (minValue(node->right) > node->data); //mid &= min(right) > data
  return isBST1(node->left) && isBST1(node->right) && mid;
}

int isBSTRecur(struct node* node, int min, int max){
  if(!node)
    return 1;
  if(node->data<=max && node->data>min)
    return isBSTRecur(node->left, min, node->data) && isBSTRecur(node->right, node->data, max);
  return 0;
}
int isBST2(struct node* node) {
  return(isBSTRecur(node, INT_MIN, INT_MAX));
}

int main(){
  int n = 4;
  struct node* vnode = NULL;
  //myNode
  struct node* myNode = build123();
  myNode = insert(myNode, -5);
  myNode = insert(myNode, -2);
  myNode = insert(myNode, -9);
  //my
  struct node* my = build123();
  myNode = insert(my, -5);
  myNode = insert(my, -2);
  myNode = insert(my, -9);
  //procedures
  printPaths(myNode);
  printPaths(vnode);
  int mySize = size(myNode);
  int maxdepth = maxDepth(myNode);
  int minVal = minValue(myNode);
  int pathsum = hasPathSum(myNode, 9);
  printf("size: %d, maxdepth: %d, minVal: %d, pathsum: %d, isBTS: %d\n", mySize, maxdepth, minVal, pathsum, isBST2(myNode));
  printf("same my: %d, same vnode: %d, count %d: %d\n", sameTree(myNode, my), sameTree(myNode, vnode), n, countDumies(n));
  printTree(myNode);
  printf("inOrder: \n");
  /*printPostorder(myNode);
  printf("postOrder: \n");*/
  mirror(myNode);
  printTree(myNode);
  printf("mirror: \n");
  printf("isBST: %d\n", isBST2(myNode));
  /*doubleTree(myNode);
  printTree(myNode);
  printf("doubleTree: \n");*/
  
  return 0;
}
