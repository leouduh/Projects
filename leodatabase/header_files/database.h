#include <stdio.h>
#include <stdlib.h>


#ifndef DATABASE_H
#define DATABASE_H
#include "datastructures.h"

// function declaration for node.c
node* createNode(value val, datatype type);
void printNodeRepresentation(node* n);

//function declaration for linekedlist.c
unsigned int lengthofLinkedList(node *phead);
linkedList* createLinkedList(value value, datatype type);
void appendToLinkedList(
    linkedList* ll, value val, datatype type
    );
void printLinkedList(linkedList* ll);
node* popNode(node *phead);
void modifyNode(node *phead, node *currNode, int position);
void insertNode(node **phead, node *currNode, int position);
void prepend(node **phead, node * currNode);


#include "../src/node.c"
#include "../src/linkedlist.c"

#endif