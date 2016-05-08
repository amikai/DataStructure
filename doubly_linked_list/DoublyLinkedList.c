#include "DoublyLinkedList.h"

void push_front(node **head, int key){
    node *new_node = (node *)malloc(sizeof(node));
    new_node->key = key;
    new_node->prev = NULL;


    if(is_empty(head)){
        new_node->next = NULL;
        (*head) = new_node;
        return ;
    }

    new_node->next = (*head);
    (*head)->prev = new_node;
    (*head) = new_node;
    return ;

}
int top_front(node **head){
    return (*head)->key;
}

void pop_front(node **head){
    if(is_empty(head)){
        fprintf(stderr, "the list is empty\n");
        return ;
    }

    if(!(*head)->next){
        free(*head);
        (*head) = NULL;
        return ;
    }

    (*head) = (*head)->next;
    free((*head)->prev);
    (*head)->prev = NULL;

}
void push_back(node **head, int key){
    node *new_node = (node *)malloc(sizeof(node));
    new_node->key = key;
    new_node->next = NULL;

    if(is_empty(head)){
        new_node->prev = NULL;
        (*head) = new_node;
        return ;
    }

    node *visit = NULL;
    for(visit = *head ; visit->next != NULL ; visit = visit->next);
    visit->next = new_node;
    new_node->prev = visit;

}
int top_back(node **head){
    node *visit = NULL;
    for(visit = *head ; visit->next != NULL ; visit = visit->next);
    return visit->key;
}
void pop_back(node **head){
    if(is_empty(head)){
        fprintf(stderr, "the list is empty\n");
        return;
    }
    if(!(*head)->next){
        free(*head);
        *head = NULL;
        return;
    }

    node *visit = NULL;
    for(visit = *head ; visit->next != NULL ; visit = visit->next);

    node *before = visit->prev;
    before->next = NULL;

    free(visit);
    visit = NULL;

}
BOOL find(node **head, int key){
    node *visit = NULL;
    for(visit = *head ; visit != NULL ; visit = visit->next)
        if(visit->key == key)
            return TRUE;

    return FALSE;
}
void erase(node **head, int key){

}
BOOL is_empty(node **head){
    if(*head)
        return FALSE;
    return TRUE;
}

node *find_node_by_key(node **head, int key){
    node *visit = NULL;
    for(visit = *head ; visit != NULL && visit->key != key ; visit = visit->next );
    return visit;
}
void add_before(node **head, node **target, int key){
    node *new_node = (node *)malloc(sizeof(node));
    new_node->key = key ;

    if((*head) == (*target)){
        push_front(head, key);
        return ;
    }

    new_node->next = (*target);
    new_node->prev = (*target)->prev;

    (*target)->prev = new_node;

    new_node->prev->next = new_node;

}
void add_after(node **head, node **target, int key){

    node *new_node = (node *)malloc(sizeof(node));
    new_node->key = key;

    if(!(*target)->next){ //last node
        push_back(head, key);
        return ;
    }

    new_node->next = (*target)->next;
    new_node->prev = (*target);

    (*target)->next = new_node;

    new_node->next->prev = new_node;
}
void print_list(node **head){
    node *visit = NULL;
    for(visit = (*head) ; visit != NULL ; visit = visit->next){
        printf("%d->",visit->key);
    }
    printf("NULL\n");
}

void print_list_reverse(node **head){
    if(is_empty(head)){
        printf("NULL\n");
        return ;
    }
    node *visit = NULL;
    for(visit = (*head) ; visit->next != NULL ; visit = visit->next);
    for( ; visit != NULL ; visit = visit->prev){
        printf("%d->",visit->key);
    }
    printf("NULL\n");
}
