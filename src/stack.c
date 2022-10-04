#include "stack.h"
#include <stdlib.h>


void initialize(stack* s){
  //implement initialize 
  //node *head=initialize();
  
  //s->head=(malloc(sizeof(node)));

  s->head=NULL;


  //s->head->next=NULL;
}

void push(int x, stack *s){
    //implement push here
    
    if (s->head==NULL) {
      s->head=(malloc(sizeof(node)));
      s->head->next=NULL;
    } 

    node* temp = s->head;

    while (temp->next!=NULL) {
      temp=temp->next;
    }


    temp->next =(malloc(sizeof(node)));
    temp->next->data = x;

    temp->next->next=NULL;

}

int pop(stack* s){
    
  node* temp = s->head;

  while (temp->next!=NULL) {
      temp=temp->next;
    }

  int value = temp->data;
  temp = NULL;

  if (s->head->next == NULL) {
    s->head=NULL;
  }

  return value;
}

bool empty(stack* s)
{
  if (s->head->next == NULL) {
    return true;
  } else {
    return false;
  }
}

//Det giver da ikke mening?? Hvad er definitionen for full?
bool full(stack* s) {
    //implement full here
  return false;
}
