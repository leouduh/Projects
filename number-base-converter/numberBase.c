#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define INPUT_WIDTH 1024






char input[INPUT_WIDTH] = "";
char baseNumber[INPUT_WIDTH] = "";
int bufferState = false;


typedef struct{
    int input, output;
}Bases;



void appendChar(char *destination, char source){
    int len = strlen(destination);
    destination[len] = source;
    destination[++len] = '\0';

}

bool isAllNumeric(char * input){
    for(int i = 0; i < strlen(input); i++){
        if (input[i] >= '0' && input[i] <= '9'){
            continue;
        }else{
            return false;
        }
    }
}



bool isEmpty(char * input){
    return (input[0])? false : true;
}

void getInput(char *input){
    char ch;
    while((ch = getchar()) != '\n'){
        appendChar(input, ch);
    }
    if (strlen(input) >= 1){
        bufferState = true;
    }
}

void flushInput(char * input){
    memset(input, '\0', INPUT_WIDTH);
    bufferState = false;
}

Bases getInputAndOutputBase(Bases bases){
    bool status = true;

    while(status){
        printf("Please enter current base of number\n");
        getInput(input);
        if(isAllNumeric(input) && (!isEmpty(input)) && atoi(input) != 0){
            bases.input = atoi(input);
            flushInput(input);
            status = false;
        }else{
            printf("Check your entry again? must be a valid number base\n");
            flushInput(input);
        }
    }
    status = true;
    while(status){
        printf("Enter base you would like to convert to \n");
        getInput(input);
        if(isAllNumeric(input) && (!isEmpty(input)) && atoi(input) != 0){
            bases.output = atoi(input);
            flushInput(input);
            status = false;
        }else{
            printf("Check your entry again? must be a valid number base\n");
            flushInput(input);
        }    
    }
    return bases;
}

void getNumber(char *baseNumber){
    printf("Please Enter your base number\n");
    getInput(baseNumber);
}


char toBaseTen(char *baseNumber){
    int val;
    char ch;
    for (int i =0; i < strlen(baseNumber); i++){
        ch = baseNumber[i];
        if (ch )
    }
}


int main(){
    Bases b;

    printf("Welcome to this program to convert numbers from one"  
    " base to another. Kindly follow the prompt and you are good to go!\n"
    );

    Bases bases = getInputAndOutputBase(b);
    printf("You wanna convert from base %d to base %d\n", bases.input, bases.output);
    getNumber(baseNumber);
    printf("%s in base %d is =========> x\n", baseNumber, bases.output);


   return 0; 
}