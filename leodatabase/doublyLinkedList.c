#include <stdio.h>
#include <stdlib.h>


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
    Value value;
    datatype type;
    struct node* next;
    struct node* prev;
}node;

typedef struct doublyLL{
    node* head;
    node* tail;
}doublyLL;

node* createNode(Value val, datatype type){
    node* n = malloc(sizeof(node)*1);
    n->value = val;
    n->type = type;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

doublyLL* createDoublyLL(Value val, datatype type){
    doublyLL* dll = malloc(sizeof(doublyLL) * 1);
    node* n = createNode(val, type);
    dll->head = n;
    dll->tail = n;
    return dll;
}

void appendToDll(doublyLL* d, Value val, datatype type){
    node* n = createNode(val, type);
    node* temp = d->head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    d->tail = n;
}

void prependToDll(doublyLL* d, Value val, datatype type){
    node* n = createNode(val, type);
    n->next = d->head;
    d->head = n;
}



int main(){
    Value a, b, c;
    a.i = 10;
    b.i = 20;
    c.i = 30;
    doublyLL* d = createDoublyLL(a, INT);
    printf("Doubly linked list has been created\n"
    "The head of the doubly linked list is at %p wih value %d\n"
    "The tail of the doubly linked list is at %p wih value %d\n"
    , d->head, d->head->value.i, d->tail, d->tail->value.i);

    appendToDll(d, b, INT);
    printf("Doubly linked list has already been created\n"
    "The head of the doubly linked list is at %p wih value %d\n"
    "The tail of the doubly linked list is at %p wih value %d\n"
    , d->head, d->head->value.i, d->tail, d->tail->value.i);


    appendToDll(d, c, INT);
    printf("Doubly linked list has already been created\n"
    "The head of the doubly linked list is at %p wih value %d\n"
    "The tail of the doubly linked list is at %p wih value %d\n"
    , d->head, d->head->value.i, d->tail, d->tail->value.i);

    return 0;
}

