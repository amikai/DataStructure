#include "LinkedList.h"

void push_front(node **head, int key){

    node *new_node = (node *)malloc(sizeof(node));
    new_node->key = key;
    if(is_empty(head)){
        new_node->link = NULL;
        (*head) = new_node;
    }else{
        new_node->link = (*head);
        (*head) = new_node;
    }
}
int top_front(node **head){
    if(is_empty(head)){
        fprintf(stderr, "the list is empty, return value -1\n");
        return -1;
    }

    return (*head)->key;
}
void pop_front(node **head){
    if(is_empty(head)){
        fprintf(stderr, "the list is empty\n");
        return;
    }

    node *temp = *head;
    (*head) = temp->link;

    free(temp);
    temp = NULL;

}
void push_back(node **head, int key){
    node *new_node = (node *)malloc(sizeof(node));
    new_node->key = key;
    new_node->link = NULL;

    if(is_empty(head)){
        (*head) = new_node;
        return;
    }

    node *visit = NULL;

    for(visit = (*head) ; visit->link != NULL ; visit = visit->link);

    visit->link = new_node;
}
int top_back(node **head){
    if(is_empty(head)){
        fprintf(stderr, "the list is empty , return value -1\n");
        return -1;
    }

    node *visit = NULL;
    for(visit = (*head) ; visit->link != NULL ; visit = visit->link);

    return visit->key;
}
void pop_back(node **head){
    if(is_empty(head)){
        fprintf(stderr, "the list is empty\n");
        return ;
    }


    if(!(*head)->link){ //only one node
        free(*head);
        *head = NULL;
    }

    node *prev = NULL;
    for(prev = (*head) ; prev->link->link != NULL ; prev = prev->link);

    free(prev->link);
    prev->link = NULL;

}
BOOL find(node **head, int key){
    node *visit = NULL;
    for(visit = (*head) ; visit != NULL ; visit = visit->link)
        if(visit->key == key)
            return TRUE;

    return FALSE;
}
void erase(node **head, int key){
    if(is_empty(head))
        return ;

    if((*head)->key == key){ //only head node
        free(*head);
        (*head) = NULL;
        return ;
    }

    node *prev = (*head);
    while(1){
        if(prev->link == NULL)
            return ;

        if(prev->link->key == key){
            node *erase = prev->link;
            prev->link = erase->link;
            free(erase);
            erase = NULL;
            return ;
        }
        prev = prev->link;
    }
}
BOOL is_empty(node **head){
    if(!(*head))
        return TRUE;
    return FALSE;
}
node *find_node_by_key(node **head, int key){
    if(is_empty(head))
        return NULL;

    node *visit = NULL;

    for(visit = (*head) ; visit != NULL && visit->key != key ; visit = visit->link);

    return visit;
}
void add_before(node **head, node **target, int key){
    if((*target) == (*head)){
        push_front(head, key);
        return ;
    }

    node *new_node = (node *)malloc(sizeof(node));
    new_node->key = key;

    node *prev = NULL;
    for(prev = (*head) ; prev->link != (*target) ; prev = prev->link);

    prev->link = new_node;
    new_node->link = (*target);

}
void add_after(node **head, node **target, int key){
    
    node *new_node = (node *)malloc(sizeof(node));
    new_node->key = key;
    new_node->link = (*target)->link;
    (*target)->link = new_node;

}
void print_list(node **head){
    node *visit = NULL;
    for(visit = (*head) ; visit != NULL ; visit = visit->link){
        printf("%d->", visit->key);
    }
    printf("NULL\n");

}
