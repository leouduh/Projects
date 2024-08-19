/*Implementing a queue using a linked list structure. 
The user should be able to perform function such as enqueue adding an element
to the back of the queue and deque removing an element from the front of the
front of the queue in a first-first-out manner, linkedlist.c is used to 
abstract these processes
Union is used so that each Node can either be an integer, float,
or a string of 64 characters maximum. The maximum size of the 
value of a node is 64 bytes.
*/
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.c"

typedef struct Queue{
    node * front;
    node * rear;
}Queue;


Queue* createQueue(Value val, datatype type);
node* findRear(node* head);
void enqueue(Queue* q, Value val, datatype type);
void emptyQueue(Queue *q);

Queue* createQueue(Value val, datatype type){
    Queue* q;
    q = malloc(sizeof(Queue)*1);
    q->front = q->rear = NULL;
    node* Node = createNode(val, type);
    q->front = Node;
    q->rear = Node;
    return q;
}

node* findRear(node * head){
    node *temp;
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    return temp;
}

void enqueue(Queue* q, Value val, datatype type){
    node* temp = createNode(val, type);
    appendNode(q->front, temp);
    //update the rear of the queue
    q->rear = findRear(q->front);   
}

void dequeue(Queue* q){
    node* temp;
    q->front = q->front->next;
    free(temp);
}

void printQueue(Queue* q){
    node* element = q->front;
    while(element->next != NULL){
        switch(element->type){
            case INT:
                printf("<====%d", element->value.i);
                break;
            case FLOAT:
                printf("<====%f", element->value.f);
                break;
            case STRING:
                printf("<====%s", element->value.s);
                break;
        }
    element = element->next;
    }
    switch(element->type){
        case INT:
            printf("<====%d", element->value.i);
            break;
        case FLOAT:
            printf("<====%f", element->value.f);
            break;
        case STRING:
            printf("<====%s", element->value.s);
            break;
    }
}

void emptyQueue(Queue* q){
    node* head = q->front;
    printf("okay\n");
    while(head->next != NULL){
        node* temp = head->next;
        free(head);
        head = temp;
    }
    free(head);
    free(q);
}
