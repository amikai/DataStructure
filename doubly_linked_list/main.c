#include "DoublyLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

    node *head = NULL;
    push_back(&head, 1);
    push_back(&head, 2);
    push_back(&head, 3);

    

    print_list(&head);
    print_list_reverse(&head);
    return 0;
}
