#ifndef __STACK_H_
#define __STACK_H_
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node* next;
} node;


typedef struct{
  node* head;
} stack;

void initialize(stack* );
void push(int, stack* );
int pop(stack*);
bool empty(stack*);
bool full(stack*);

#endif // __STACK_H_
