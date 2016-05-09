#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"



#define STACK_SIZE 3


int main(){

    stack *s = creat_stack(3);
    push(s, 1);
    push(s, 2);
    push(s, 3);

    pop(s);
    pop(s);
    pop(s);

}
