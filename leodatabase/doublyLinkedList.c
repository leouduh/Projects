#include <stdio.h>



typedef union Value{
    int i;
    float f;
    char s[64];
}Value;

typedef enum datatype{
    INT,
    FLOAT,
    STRING, 
}datatype;


typedef struct node{
    Value val;
    datatype type;
    node* next;
    node* prev;
}node;

typedef struct doublyLL{
    node* head;
    node* tail;
}doublyLL;

node* createNode(Value val, datatype type){
    node* n = malloc(sizeof(node)*1);
    n->val = val;
    n->type = type;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

doublyLL* createDoublyLL(Value val, datatype type){
    doublyLL* dll = malloc(sizeof(doublyLL) * 1);
    node* n = createNode(val, type);
}

