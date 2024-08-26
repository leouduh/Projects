/*
This is the core implementation of a linkedlist
The structure for a linked list is defined here alongside
functions to edit a linked list



*/

#include "../header_files/datastructures.h"
#include "../header_files/database.h"


linkedList* createLinkedList(value value, datatype type){
    //This creates a pointer to head node phead, this is the starting point
    //of the linked list.
    linkedList* ll = malloc(sizeof(linkedList) * 1);
    node* n = createNode(value, type);
    ll->head = n;
    return ll;
}

void printLinkedList(linkedList* ll){
    //Prints the linked list to the console int the format 
    //node1--->node2---->node3---->NULL
    node* temp = ll->head;
    while(temp->next != NULL){
        printNodeRepresentation(temp);
        printf("---->");
        temp = temp->next;
    }
    printNodeRepresentation(temp);
    printf("----> NULL");
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
            phead->val = currNode->val;
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
            temp->val = currNode->val;
            temp->type = currNode->type;
            free(currNode);
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


void prepend(node **pphead, node * currNode){
    //makes currNode the new pointer of the linked list.
    currNode->next = *pphead;
    *pphead = currNode;
}

void appendToLinkedList(
    linkedList* ll, value val, datatype type
    )
    {
    node* n = createNode(val, type);
    node* temp = ll->head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->next;
}