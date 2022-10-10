#include "stack.h"
#include <stdlib.h>

//initializes the stack
void initialize(stack* s){
  
  s->head=NULL;

}

//pushes a new element to the stack. Checks if the stack is empty or not.
//If the stack is empty, memory is allocated for head, and next is set to NULL.
void push(int x, stack *s){
    //implement push here
    
    if (s->head==NULL) {
      s->head=(malloc(sizeof(node)));
      s->head->next=NULL;
    } 

    node* temp = s->head;

    //Travel to the end of the list
    while (temp->next!=NULL) {
      temp=temp->next;
    }

    //Allocate memory for the new node at the end of the list and insert the value.
    temp->next =(malloc(sizeof(node)));
    temp->next->data = x;

    temp->next->next=NULL;

}

int pop(stack* s){
    
  node* temp = s->head;

  //Travels to the end of the list
  while (temp->next->next!=NULL) {
      temp=temp->next;
    }

  //Saves the value of the last node
  int value = temp->next->data;

  
  temp->next = NULL;

  //If the list is empty, free the memory allocated for head.
  if (s->head->next == NULL) {
    s->head=NULL;
  }
  return value;
}

bool empty(stack* s)
{

  //if head is NULL, the list is empty.
  if (s->head->next == NULL) {
    return true;
  } else {
    return false;
  }
}

//A stack can't be full..? Unless you run out of memory.
bool full(stack* s) {
    //implement full here... (Again, a stack can't be full..?)
  return false;
}
