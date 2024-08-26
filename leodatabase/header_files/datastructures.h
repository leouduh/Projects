#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

typedef union value{
    int i;
    float f;
    char s[256];
}value;

typedef enum datatype{
    INT,
    FLOAT,
    STRING,
}datatype;

typedef struct node{
   value val;
   datatype type;
   struct node* next;
   struct node* prev; 
}node;

typedef struct linkedList{
    node* head;
    node* tail; 
}linkedList; 


#endif

