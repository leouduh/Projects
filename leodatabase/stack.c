/*
Implementation of a stack building on top of linked lists

*/

#include "linkedlist.c"

typedef struct stack{
    node* front;
    node* back;
}stack;

stack* createStack(Value val, datatype type){
    node* n = createNode(val, type);
    stack* s = malloc(sizeof(stack)* 1);
    s->front = n;
    s->back = n;
    return s;
}

void appendToStack(stack *s, Value val, datatype type){
    node* n = createNode(val, type);
    // node
}
