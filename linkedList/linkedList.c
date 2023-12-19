#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};

struct Node* BuildOneTwoThree(){
  struct Node* head = malloc(sizeof(struct Node));
  
  head -> data = 1;
  head -> next = malloc(sizeof(struct Node));
  
  (head->next) -> data = 2;
  (head->next) -> next = malloc(sizeof(struct Node));

  ((head->next)->next) -> data = 3;
  ((head->next)->next) -> next = NULL;

  return head;
}
int Length(struct Node* head){
  struct Node* current = head;
  int count = 0;

  while(current != NULL){
    count++;
    current = current -> next;
  }

  return count;
}
void LengthTest(){
  struct Node* myList = BuildOneTwoThree();
  int len = Length(myList);
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
  LengthTest();
  return 0;
}
