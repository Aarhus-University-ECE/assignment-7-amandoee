#include "stack.h"
#include <stdlib.h>

struct node *prev, *head, *p;


void initialize(stack* s){
  //implement initialize 
  int n;
  //allocating memory
  //ptr = (struct stack*)malloc(sizeof(struct stack));
  printf ("number of elements:");
  scanf("%d",&n);
  
  head=NULL;
  for (int i=0;i<n;i++)
    {
        p=malloc(sizeof(struct node));
        scanf("%d",&p->data);
        p->next=NULL;
        if(head==NULL)
            head=p;
        else
            prev->next=p;
        prev=p;
    }

}

void push(int x, stack* s){
    //implement push here
}

int pop(stack* s){
    // implement pop here
  return -1;
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
