#include "stack.h"
#include <stdlib.h>


void initialize(stack* s){
  //implement initialize 
  s->head = NULL;

}

void push(int x, stack *s){
    //implement push here
    s = (struct stack *)malloc(sizeof(struct stack));
    s->head->data = x;

    //->data = x; //Angiver x som data til stacken

    if (s->head==NULL) {
      s->head->next = NULL;
    } else {
      s->head->next = s->head;
    }
    s->head = s; 
    //top refererer til den nyeste skabte node
    



}

int pop(stack* s){
    // implement pop here

    //Tjek for om der er indhold i stack at fjerne.
    if (s->head == NULL) {
      printf("\n Tom stack!");
    } else {
      s = s->head;
      int temp_data = s->head->data;
      s->head = s->head->next;
      free(s);
      return temp_data;
    }
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
