#include "stack.h"
#include <stdlib.h>

struct node *head = NULL;

void initialize(stack* s){
  //implement initialize 
  s->head = NULL;

}

void push(int x, stack *s){
    //implement push here

    s = malloc(sizeof(struct node));
    s->head->data = x;

    //lav en ny node der pointer til headernoden
    s->head->next = s->head;

    //make the new node as head node
    //so that head will always point the last inserted data
    s->head = s;

}

int pop(stack* s){
    // implement pop here

    struct node *temp;

    if (s->head==NULL) {
      printf("stack er tom");
    } else {
      printf("Fjernede element er %d \n", head->data);

      temp = s->head;

      s->head = s->head->next;

      free(temp);


    }
    //Tjek for om der er indhold i stack at fjerne.
    
}

bool empty(stack* s)
{
  //implement empty here
  return false;
}

bool full(stack* s) {
    //implement full here
  return false;
}
