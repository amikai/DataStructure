#include "ArrayStack.h"


stack *creat_stack(int max_size){
    stack *s = (stack *)malloc(sizeof(stack));
    s->num_elements = 0;
    *(int *)(&s->MAX_STACK_SIZE) = max_size; // initial struc const member
    s->datas = (int *)calloc(max_size,0);

    return s;
}

void push(stack *s,int data){
    if(is_full(s)){
        fprintf(stderr, "the stack is full\n");
        return ;
    }
    s->datas[(s->num_elements)++] = data;
}

int top(stack *s){

    if(is_empty(s)){
        fprintf(stderr, "the stack is empty\n");
        return -1;
    }
    return s->datas[s->num_elements - 1];
}

int pop(stack *s){
    if(is_empty(s)){
        fprintf(stderr, "the stack is empty\n");
        return -1;
    }

    return s->datas[--(s->num_elements)];
}

BOOL is_empty(stack *s){
    if(s->num_elements == 0)
        return TRUE;
    return FALSE;
}

BOOL is_full(stack *s){
    return s->num_elements == s->MAX_STACK_SIZE;
}

void print_stack(stack *s){
    int i = 0;
    printf("top");
    for(i = s->num_elements - 1  ; i >= 0 ; i--){
        printf("->%d",s->datas[i]);
    }
    printf("\n");
}
