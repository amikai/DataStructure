#include "LinkedStack.h"

void push(element **top, int data){
    element *new_element = (element *)malloc(sizeof(element));
    new_element->data = data;

    new_element->link = (*top);
    (*top) = new_element;

}
int top(element **top){
    if(is_empty(top)){
        fprintf(stderr, "the stack is empty\n");
        exit(1);
    }
    return (*top)->data;
}
int pop(element **top){
    if(is_empty(top)){
        fprintf(stderr, "the stack is empty\n");
        exit(1);
    }
    element *temp = *top;
    (*top) = temp->link;

    int data = temp->data;

    free(temp);
    temp = NULL;

    return data;
}
BOOL is_empty(element **top){
    if(!(*top))
        return TRUE;
    return FALSE;
}

void print_stack(element **top){
    element *visit = NULL;
    printf("top");
    for(visit = (*top) ; visit != NULL ; visit = visit->link){
        printf("->%d",visit->data);
    }
    printf("\n");
}
