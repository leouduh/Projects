/*
Implementation of a stack building on top of linked lists

*/

// #include "linkedlist.c"
#include "doublyLinkedList.c"

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
    n->next = NULL;
    n->prev = s->back;
    s->back = n;
}

void printStack(stack* s){
    node* tempNode = s->back;
    while (tempNode->prev != NULL){
        printNodeRepresentation(tempNode);
        printf("\n");
        tempNode = tempNode->prev;
    }
    printNodeRepresentation(tempNode);
}

int main(){
    Value a, b, c;
    a.i = 100;
    stack* s = createStack(a, INT);
    printf("You just created a stack and its memory address is: %p ", s);
    b.f = 4.5;
    c.f = 10.5; 
    appendToStack(s, b, FLOAT);
    appendToStack(s, c, FLOAT);
    printf("Just added to the stack, it now looks like: \n");
    printStack(s);
    



    return 0;
}
