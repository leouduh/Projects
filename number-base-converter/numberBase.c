#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#define INPUT_WIDTH 1024






char input[INPUT_WIDTH] = "";
char baseNumber[INPUT_WIDTH] = "";
int bufferState = false;
int hexmapOffSet = 6; 
int errorStatus = 0;
char desiredBase[INPUT_WIDTH] = "";


typedef struct{
    int input, output;
}Bases;

char hexmap[6] = {
    'a', 'b', 'c', 'd', 'e', 'f',
};

int hexValues[6] = {
    10, 11, 12, 13, 14, 15
};

int hexmapValue(char hexCharacter){
    for(int i=0; i < 6; i++){
        if((hexmap[i] == hexCharacter)|| (hexmap[i] == tolower(hexCharacter))){
            return hexValues[i];
        }
    }
}



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


int toBaseTen(char *baseNumber, Bases b){
    int val = 0;
    char ch[1] = "";
    for (int i = 0;  i < strlen(baseNumber) ; i++){
        ch[0] = baseNumber[i];
        if ((ch[0] >= 'a' && ch[0] <= 'f')||(ch[0] >= 'A' && ch[0] <= 'F')){
            val += hexmapValue(ch[0]) * (int)pow(b.input, strlen(baseNumber)-i-1);
        }else{
            val += atoi(ch) * (int)pow(b.input, strlen(baseNumber) - i-1);
        }
    }
    return val;
}

bool isBaseNumberValid(char * baseNumber, Bases b){
    char ch[1] = "";
    for(int i = 0; i < strlen(baseNumber); i++){
        ch[0] = baseNumber[i];
        if((b.input == 16) && (isalpha(ch[0]))){
            if (!((ch[0] >= 'a' && ch[0] <= 'f')||(ch[0] >= 'A' && ch[0] <= 'F'))){
                return false;
            }
        }else if(atoi(ch) >= b.input){
            return false;
        }
    }
    return true;
}


convertBase();

int main(){
    Bases b;

    printf("Welcome to this program to convert numbers from one"  
    " base to another. Kindly follow the prompt and you are good to go!\n"
    );

    Bases bases = getInputAndOutputBase(b);
    printf("You wanna convert from base %d to base %d\n", bases.input, bases.output);
    getNumber(baseNumber);
    while (isBaseNumberValid(baseNumber, bases)==false){
        printf("The number you have entered is not a valid number in base %d\n", bases.input);
        flushInput(baseNumber);
        getNumber(baseNumber);
    }
    printf("%s in base %d is =========> x\n", baseNumber, bases.output);
    // Bases b;
    // b.input = 16;
    // b.output = 10;
    // char bn[10] = "A24";

    // printf("%s, is %d in base 10", bn, toBaseTen(bn, b));


   return 0; 
}