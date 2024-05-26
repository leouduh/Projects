#include <stdio.h>
#include <stdlib.h>



typedef struct node{
    int value;
    struct node* next;
}node;

node* createNode(int value){
    //creates a node, return pointer to a node
    node* Node;
    Node = malloc(sizeof(node)*1);
    Node->value = value;
    Node->next = NULL;   
    return Node;
}

int lengthofLinkedList(node *phead);
node* createLinkedList(int value);
void appendNode(node *phead, node *currNode);
void printLinkedList(node* phead);
node* popNode(node *phead);
void replaceNode(node *phead, node *currNode, int position);
void insertNode(node **phead, node *currNode, int position);
void prepend(node **phead, node * currNode);


node* createLinkedList(int value){
    //This creates a pointer to head node phead, this is the starting point
    //of the linked list.
    node* phead;
    phead = createNode(value);
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
        printf("%d---->", temp->value);
        temp = temp->next;
    }
    printf("%d--->NULL\n", temp->value);
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

void replaceNode(node *phead, node *currNode, int position){
    //Using zero index to insert a Node in the linked list
    if(position > lengthofLinkedList(phead)-1){
        printf("You are attempting to replace a node that does not exist"
        ". Position is out of bounds!");
        return;
    }
    switch(position){
        case 0:
            phead->value = currNode->value;
            currNode->next = phead->next;
            phead = currNode;
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
            free(currNode);
        }
}

void insertNode(node **pphead, node *currNode, int position){
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

int lengthofLinkedList(node *phead){
    int length = 1;
    node *temp = phead;
    while(temp->next != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

void prepend(node **pphead, node * currNode){
    //pointer to pointer
    currNode->next = *pphead;
    *pphead = currNode;
}

int main(){
    node* phead;
    phead = createLinkedList(5);
    printf("You just created a node the value of the node is %d\n", phead->value);
    printf("This node points to %p\n", phead->next);
    node *node1, *node2, *node3, *node4;
    node1 = createNode(10);
    appendNode(phead, node1);

    node2 = createNode(20);
    appendNode(phead, node2);

    node3 = createNode(30);
    appendNode(phead, node3);

    node4 = createNode(40);
    appendNode(phead, node4);

    printf("\n Adding a bunch of nodes ---------\n");
    printf("Linked list now looks like: ");
    printLinkedList(phead);

    
    node *n = popNode(phead);
    printf("Node %d has been popped off\n: ", n->value);
    printLinkedList(phead);


    // popNode(phead);
    // printf("Node has been popped off, now linked list is: ");
    // printLinkedList(phead);


    // node *n;
    // n = createNode(100);
    // replaceNode(phead, n, 0);
    // printf("Node in position 0 has now been replaced ");
    // printLinkedList(phead);

    // node *k;
    // k = createNode(88);
    // replaceNode(phead, k, 0);
    // printf("Node in position 0 has now been replaced ");
    // printLinkedList(phead);

    // node *m = createNode(666);
    // printf("%p\n", m);
    // prepend(&phead, m);
    // printf("Item has been prepended to list\n");
    // printLinkedList(phead);

    // appendNode(phead, createNode(419));
    // printLinkedList(phead);


    // printf("The length of the linked list is now %d\n", lengthofLinkedList(phead));

    // replaceNode(phead, createNode(69), 1);
    // printf("Node in position 1 how now been replaced. linked list is now: ");
    // printLinkedList(phead);

    // replaceNode(phead, createNode(2024), 3);
    // printf("Node in position 1 how now been replaced. linked list is now: ");
    // printLinkedList(phead);

    // insertNode(&phead, createNode(100), 5);
    // printf("I just inserted 100 in position 0: Linked list is now: ");
    // printLinkedList(phead);

    return 0;
}