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

node *find_node_by_key(node **head, int key){ return NULL;}
void add_before(node **head, node ** target, int key){}
void add_after(node **head, node **target, int key){}
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
