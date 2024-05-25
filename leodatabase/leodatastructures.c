#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int value;
    struct node* next;
}node;

node* createNode(int value){
    //creates a node 
    node* Node;
    Node = malloc(sizeof(node)*1);
    Node->value = value;
    Node->next = NULL;   
    return Node;
}

node* createLinkedList(int value){
    //Uses createNode function to create linked list
    // all we need for a linked list is the head really
    // with the head we can perform do all we need to do.
    node* head;
    head = createNode(value);
}


void appendNode(node* head, node* currNode){
    //Appends a node currNode to the end of the linked list
    //last node will point to currNode instead and currNode
    //Will in turn point to NULL
    node* temp;
    temp = head;
    while(temp->next != NULL){
        temp = temp->next; 
    }
    temp->next = currNode;

}

void printLinkedList(node* head){
    node* temp;
    temp = head;
    while(temp->next != NULL){
        printf("%d---->", temp->value);
        temp = temp->next;
    }
    printf("%d\n", temp->value);
}

void popNode(node *head){
    node *temp;
    temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void replaceNode(node *head, node *currNode, int position){
    //Using zero index to insert a Node in the linked list
    if(position == 0){
        head->value = currNode->value;
        currNode->next = head->next;
        head = currNode;
        free(currNode);
    }
}

int lengthofLinkedList(node *head){
    int length = 1;
    node *temp = head;
    while(temp->next != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

void prepend(node **head, node * currNode){
    //pointer to pointer
    currNode->next = *head;
    *head = currNode;
}

int main(){
    node* head;
    head = createLinkedList(5);
    printf("You just created a node the value of the node is %d\n", head->value);
    printf("This node points to %p\n", head->next);
    node *node1, *node2, *node3, *node4;
    node1 = createNode(10);
    appendNode(head, node1);

    node2 = createNode(20);
    appendNode(head, node2);

    node3 = createNode(30);
    appendNode(head, node3);

    node4 = createNode(40);
    appendNode(head, node4);

    printf("\n Adding a bunch of nodes ---------\n");
    printf("Linked list now looks like: ");
    printLinkedList(head);

    
    popNode(head);
    printf("Node has been popped off, now linked list is: ");
    printLinkedList(head);


    popNode(head);
    printf("Node has been popped off, now linked list is: ");
    printLinkedList(head);


    node *n;
    n = createNode(100);
    replaceNode(head, n, 0);
    printf("Node in position 0 has now been replaced ");
    printLinkedList(head);

    node *k;
    k = createNode(88);
    replaceNode(head, k, 0);
    printf("Node in position 0 has now been replaced ");
    printLinkedList(head);

    node *m = createNode(666);
    printf("%p\n", m);
    prepend(&head, m);
    printf("Item has been prepended to list\n");
    printLinkedList(head);

    appendNode(head, createNode(419));
    printLinkedList(head);


    printf("The length of the linked list is now %d\n", lengthofLinkedList(head));



    return 0;
}