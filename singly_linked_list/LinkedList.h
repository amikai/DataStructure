
#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <stdlib.h>
#include <stdio.h>
#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct node{
    int value;
    struct node *link;
}node;

void push_front(node **head, int key); //add to front
int top_front(node **head); //return front item
void pop_front(node **head); //remove front item
void push_back(node **head, int key); //add to back
int top_back(node **head); //return back item
void pop_back(node **head); //remove back item
BOOL find(node **head, int key); // is key in list?
void erase(node **head, int key); // remove key from list
BOOL empty(node **head); //is list empty?
void add_before(node **head, node ** target, int key); //add key before target node
void add_after(node **head, node **target, int key); //add key after target node

void printHello();


#endif
