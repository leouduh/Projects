#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define INPUT_WIDTH 1024


char input[INPUT_WIDTH] = "";
int bufferState = false;


typedef struct{
    int input, output;
}Bases;


Bases bases;
bases = {0, 0};


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

Bases getInputAndOutputBase(){


    // while()

    printf("Please enter current base of number\n");
    getInput(input);
    if(isAllNumeric(input) && (!isEmpty(input)) && atoi(input) != 0){

    }
}

int main(){

    int numericTest, emptyTest;
    printf("Please enter something into the terminal\n");

    getInput(input);
    printf("What you entered into the terminal is: \"%s\"\n", input);
    numericTest = isAllNumeric(input);
    emptyTest = isEmpty(input);
    printf("Is your entry empty?: %s\n", emptyTest? "true": "false");
    printf("Is what you entered all numeric?: %s\n", numericTest ? "true": "false");
    flushInput(input);
    printf("The input has now been emptied, the content is: %s, the length is %d\n", input, strlen(input));

 
   return 0; 
}