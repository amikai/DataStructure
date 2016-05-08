#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


int main(){

    node *head = NULL;
    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);

    print_list(&head);

    return 0;
}
