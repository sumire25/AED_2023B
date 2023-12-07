#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* create(){
  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;

  head = malloc(sizeof(struct Node));
  second = malloc(sizeof(struct Node));
  third = malloc(sizeof(struct Node));

  head -> data = 1;
  head -> next = second;

  second -> data = 2;
  second -> next = third;
  
  third -> data = 3;
  third -> next = NULL;

  return head;
}

void printLinkedList(struct Node* head){
  while(head){
    printf("%d ", head -> data);
    head = head -> next;
  }
  printf("\n");
}
void release(struct Node* head){
  struct Node* aux;
  while(head){
    aux = head -> next;
    free(head);
    head = aux;
  }
}

int main(){
  struct Node* list = create();
  
  printf("HI\n");
  printLinkedList(list);

  release(list);

  return 0;
}
