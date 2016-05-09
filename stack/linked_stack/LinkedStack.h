#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <stdlib.h>
#include <stdio.h>

#ifndef BOOL
#define BOOL int
#define TRUE 1
#define FALSE 0
#endif

typedef struct element{
    int data;
    struct element *link;
}element;

void push(element **top, int data);
int top(element **top);
int pop(element **top);
BOOL is_empty(element **top);
BOOL is_full(element **top);
void print_stack(element **top);

#endif
