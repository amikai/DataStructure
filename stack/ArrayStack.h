



#ifndef ARRAY_STACK_H
#define  ARRAY_STACK_H



#include <stdlib.h>
#include <stdio.h>
#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct{
    int *element;
    int num_elements;
    const int MAX_STACK_SIZE;
}stack;

stack *creat_stack(int max_size);
void push(stack *s, int key);
int top(stack *s);
int pop(stack *s);
BOOL is_empty(stack *s);
BOOL is_full(stack *s);
void print_stack(stack *s);

#endif
