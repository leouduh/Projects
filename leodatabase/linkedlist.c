#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union Value{
    int i;
    float f;
    char s[64];
}Value;

typedef enum{
    INT, FLOAT, STRING
}datatype;

typedef struct node{
    datatype type;
    Value value;
    struct node* next;
}node;

node* createNode(Value value, datatype type){
    //creates a node, return pointer to a node
    node* Node;
    Node = malloc(sizeof(node)*1);
    Node->type = type;
    Node->value = value;
    Node->next = NULL;   
    return Node;
}

unsigned int lengthofLinkedList(node *phead);
node* createLinkedList(Value value, datatype type);
void appendNode(node *phead, node *currNode);
void printLinkedList(node* phead);
node* popNode(node *phead);
void modifyNode(node *phead, node *currNode, int position);
void insertNode(node **phead, node *currNode, int position);
void prepend(node **phead, node * currNode);


node* createLinkedList(Value value, datatype type){
    //This creates a pointer to head node phead, this is the starting point
    //of the linked list.
    node* phead;
    phead = createNode(value, type);
}


void appendNode(node* phead, node* currNode){
    //Appends a node currNode to the end of the linked list
    //last node will point to currNode instead and currNode
    //Will in turn now point to NULL
    node* temp;
    temp = phead;
    while(temp->next != NULL){
        temp = temp->next; 
    }
    temp->next = currNode;

}

void printLinkedList(node* phead){
    //Prints the linked list to the console int the format 
    //node1--->node2---->node3---->NULL
    node* temp;
    temp = phead;
    while(temp->next != NULL){
        switch(temp->type){
            case INT:
                printf("%d---->", temp->value.i);
                break;
            case FLOAT:
                printf("%f---->", temp->value.f);
                break;
            case STRING:
                printf("%s---->", temp->value.s);
        }
        temp = temp->next;
    }
    switch(temp->type){
        case INT:
            printf("%d---->NULL", temp->value.i);
            break;
        case FLOAT:
            printf("%f---->NULL", temp->value.f);
            break;
        case STRING:
            printf("%s---->NULL", temp->value.s);
    }
    // printf("%d--->NULL\n", temp->value);
}

node* popNode(node *phead){
    //Removes the last node from the linked list and returns pointer to the
    //last node.
    node *temp;
    temp = phead;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    node *ans = temp->next;
    temp->next = NULL;
    return ans;
}

void modifyNode(node *phead, node *currNode, int position){
    //modifies value of a node, this can easily be shortened.
    if(position > lengthofLinkedList(phead)-1){
        printf("You are attempting to modify a node that does not exist"
        ". Position is out of bounds!");
        return;
    }
    switch(position){
        case 0:
            phead->value = currNode->value;
            phead->type = currNode->type;
            free(currNode);
            return;
            break;
        default:
            int i=0;
            node *temp = phead;
            do{
                temp = temp->next;
                i++;
            }while(i != position);
            temp->value = currNode->value;
            temp->type = currNode->type;
            free(currNode);
        }
}

void insertNode(node **pphead, node *currNode, int position){
    //Inserts Node in position of linked list and right shifts linked list 
    if(position > lengthofLinkedList(*pphead)){
        printf("Insertion operation out of bounds!!!!\n");
        return;
    }
    switch(position){
        case 0:
            currNode->next = *pphead;
            *pphead = currNode;
            return; 
            break;
        default:
            node *temp = *pphead;
            for(int i=0; i < position - 1; i++){
                temp = temp->next;
                }
        currNode->next = temp->next;
        temp->next = currNode;
    }
}

unsigned int lengthofLinkedList(node *phead){
    //Returns the length of the linked list
    int length = 1;
    node *temp = phead;
    while(temp->next != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

void prepend(node **pphead, node * currNode){
    //makes currNode the new pointer of the linked list.
    currNode->next = *pphead;
    *pphead = currNode;
}