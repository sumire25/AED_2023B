#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
};

void Push(struct node** headRef, int data) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = *headRef; // The '*' to dereferences back to the real head
  *headRef = newNode; // ditto
}

struct node* BuildWithLocalRef() {
  struct node* head = NULL;
  struct node** lastPtrRef= &head; // Start out pointing to the head pointer
  int i;

  for (i=1; i<6; i++) {
  Push(lastPtrRef, i); // Add node at the last pointer in the list
  lastPtrRef= &((*lastPtrRef)->next); // Advance to point to the
  // new last pointer
  }

  // head == {1, 2, 3, 4, 5};
  return(head);
}

void printLinkedList(struct node* head){
  while(head){
    printf("%d ", head -> data);
    head = head -> next;
  }
  printf("\n");
}

void release(struct node* head){
  struct node* aux;
  while(head){
    aux = head -> next;
    free(head);
    head = aux;
  }
}

int main(){
  struct node* Node = BuildWithLocalRef();
  printLinkedList(Node);
  return 0;
}
