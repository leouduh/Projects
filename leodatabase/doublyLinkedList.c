#include <stdio.h>
#include <stdlib.h>
#include <string.h>



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



node* createNode(Value val, datatype type);
doublyLL* createDoublyLL(Value val, datatype type);
void appendToDll(doublyLL* d, Value val, datatype type);
void prependToDll(doublyLL* d, Value val, datatype type);
void printNodeRepresentation(node* n);
void printDll(doublyLL* d);
unsigned int lengthOfDoublyLinkedList(doublyLL* d);
void deleteDoublyLinkedList(doublyLL* d);


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


unsigned int lengthOfDoublyLinkedList(doublyLL* d){
    node* temp = d->head;
    unsigned int length = 1;
    while(temp->next != NULL){
        length += 1;
        temp = temp->next;
    }
    return length;
}


void prependToDll(doublyLL* d, Value val, datatype type){
    node* n = createNode(val, type);
    d->head->prev = n;
    n->next = d->head;
    d->head = n;
}

void printNodeRepresentation(node* n){
    switch(n->type){
        case INT:
            printf("%d <---> ", n->value.i);
            break;
        case FLOAT:
            printf("%f <---> ", n->value.f);
            break;
        case STRING:
            printf("%s <---> ", n->value.s);
            break;
    }
}

void printDll(doublyLL* d){
    node *temp = d->head;
    while(temp != NULL){
        printNodeRepresentation(temp);
        temp = temp->next;
    }
    printf("NULL\n");

}

void deleteDoublyLinkedList(doublyLL* d){
    node* curr_node = d->tail;
    node* temp = curr_node;
    while(curr_node != NULL){
        temp = curr_node;
        curr_node = curr_node->prev;
        free(temp);
    }
}


int main(){
    Value a, b, c, e;
    a.i = 10;
    b.i = 20;
    c.i = 30;
    strcpy(e.s, "Example");
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


    Value f;
    strcpy(f.s, "START");
    prependToDll(d, f, STRING);
    
    appendToDll(d, e, STRING);
    printf("\n\nThe doubly linked list looks like: ");
    printDll(d);

    printf(
        "The length of the doubly linked list is: %d\n\n", lengthOfDoublyLinkedList(d)
        );
    printf("Time to delete the doubly linked list\n");
    deleteDoublyLinkedList(d);
    printf("\n\nDoubly linked list is empty it is now: \n");
    printDll(d);

    return 0;
}

