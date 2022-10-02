/*
 * Evaluation of an expression.
 */

#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */
#include <stdbool.h> /* bool, true, false */

#define SIZE 4      /* size of the expression array */
#define ROOT_NODE 0 /* index of the root node */
#define EXPR_NODE 1 /* index of the child of the root node */
#define SENTINEL -1 /* sentinel signalling that the evaluation has finished */

typedef enum
{
    ROOT,
    NUMBER,
    OPERATOR
} command;

typedef struct
{
    command com; /* command of the node */
    int num;     /* the number if com == NUMBER */
    char op;     /* the operator if com == OPERATOR */
    int lchild;  /* left child of operator */
    int rchild;  /* right child of operator */
} node;


/* program body */
int main(void)
{
node expr[SIZE] =
{
    {ROOT, 0, 0, 0, 0},
    {OPERATOR, 0, '+', 2, 3},
    {NUMBER, 6, 0, 0, 0},
    {NUMBER, 7, 0, 0, 0},
};

    int curr; /* current node */
    /* next specifies where to continue the evaluation after the current node. */
    int next[SIZE];
    /* eval[i] stores result of the evaluation of node i. */
    int eval[SIZE];
    /* If done[i] is true when a node is visited, the children have been evaluated. */
    bool done[SIZE];
    int i; /* counter variable */

    /* precondition */
    /* true */

    /* postcondition */
    /* initialise done indicating that no node has been visited */
    for (i = 0; i < SIZE; i = i + 1)
        done[i] = false;

    curr = ROOT_NODE; /* start at the root */
    next[curr] = SENTINEL;
    while (curr != SENTINEL)
    {
        switch (expr[curr].com)
        {
        case ROOT:
            if (!done[curr])
            { /* after evaluating EXPR_NODE, evaluate ROOT_NODE */
                next[EXPR_NODE] = ROOT_NODE;
                done[ROOT_NODE] = true;
                curr = EXPR_NODE; /* continue evaluation at EXPR_NODE */
            }
            else
            { /* copy result of evaluation of EXPR_NODE into ROOT_NODE */
                eval[ROOT_NODE] = eval[EXPR_NODE];
                curr = next[curr]; /* end evaluation: next[curr] == sentinel */
            }
            break;
        case NUMBER:
            /* the result of evaluation a number is the number itself */
            eval[curr] = expr[curr].num;
            done[curr] = true;
            curr = next[curr]; /* continue evaluation */
            break;
        case OPERATOR:
            if (!done[curr])
            { /* after evaluating the left child, evaluate the right child */
                next[expr[curr].lchild] = expr[curr].rchild;
                /* after evaluating the right child, evaluate the current node */
                next[expr[curr].rchild] = curr;
                done[curr] = true;
                /* continue evaluation at left child */
                curr = expr[curr].lchild;
            }
            else
            { /* carry out specified operation */
                switch (expr[curr].op)
                {
                case '+':
                    eval[curr] = eval[expr[curr].lchild] + eval[expr[curr].rchild];
                    break;
                case '-':
                    eval[curr] = eval[expr[curr].lchild] - eval[expr[curr].rchild];
                    break;
                case '*':
                    eval[curr] = eval[expr[curr].lchild] * eval[expr[curr].rchild];
                    break;
                case '/':
                    eval[curr] = eval[expr[curr].lchild] / eval[expr[curr].rchild];
                    break;
                default:
                    abort();
                }
                curr = next[curr]; /* continue evaluation */
            }
            break;
        default:
            abort();
        }
    }

    printf("%d\n", eval[ROOT_NODE]);

    /* return from body and exit program */
    return 0;
}