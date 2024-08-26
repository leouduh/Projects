/*This is the core definition of a node

Rudimentary functions are defined in here.

Creating a node and printing the representation of a node

A node would have previous and next elements: a single or
doublylinked list would use the parts needed.


*/

#include "../header_files/database.h"


node* createNode(value val, datatype type){
    node* n = malloc(sizeof(node)* 1);
    n->val = val;
    n->next = NULL;
    n->prev = NULL;
    n->type = type;
}

void printNodeRepresentation(node* n){
    switch(n->type){
        case INT:
            printf("%i", n->val.i);
            break;
        case FLOAT:
            printf("%f", n->val.f);
            break;
        case STRING:
            printf("%s", n->val.s);
            break;
    }
}
