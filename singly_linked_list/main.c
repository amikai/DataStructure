#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(){

    node *head = NULL;
    push_back(&head, 1);
    pop_front(&head);


    print_list(&head);

    return 0;
}
