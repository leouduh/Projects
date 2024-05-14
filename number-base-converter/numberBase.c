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
bool programStatus = true;
bool innerProgramStatus = true;


typedef struct{
    int input, output;
}Bases;

typedef struct{
    int baseTen;
    char * otherBases; 
}DesiredBase;

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

char reverseHexmapValue(int hexValue){
    for(int i=0; i < 6; i++){
        if((hexValues[i] == hexValue)|| (hexValues[i] == tolower(hexValue))){
            return hexmap[i];
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

bool inRange(char *input){
    if (isAllNumeric(input)){
        if ((atoi(input)) >= 2 && (atoi(input)) <= 16){
            return true;
        }

    }
    return false;
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
        printf("Please enter current base of number:\n");
        getInput(input);
        if(isAllNumeric(input) && (!isEmpty(input)) && atoi(input) != 0 && inRange(input)){
            bases.input = atoi(input);
            flushInput(input);
            status = false;
        }else{
            printf("Check your entry again? must be a valid number base, make sure that all characters are digits and that the base you enter ed is between 2 and\n");
            flushInput(input);
        }
    }
    status = true;
    while(status){
        printf("Enter base you would like to convert to \n");
        getInput(input);
        if(isAllNumeric(input) && (!isEmpty(input)) && atoi(input) != 0 && inRange(input)){
            bases.output = atoi(input);
            flushInput(input);
            status = false;
        }else{
            printf("Check your entry again? must be a valid number base, make sure that all characters are digits and that the base you enter ed is between 2 and\n");
            flushInput(input);
        }    
    }
    return bases;
}

void getNumber(char *baseNumber){
    printf("Please Enter your base number\n");
    getInput(baseNumber);
}

char intToCharUnder10(int val){
    return '0' + val;
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
        if((b.input > 10) && (isalpha(ch[0]))){
            if (!((ch[0] >= 'a' && ch[0] <= reverseHexmapValue(b.input))||(ch[0] >= 'A' && ch[0] <= toupper(reverseHexmapValue(b.input))))){
                return false;
            }
        }else if(isdigit(ch[0])){
            if (atoi(ch) >= b.input){
            return false;
            } 
        }else if (!isdigit(ch[0])){
            return false;
        }
    }
    return true;
}

void reverseString(char * str) {
    int i, j;
    char temp;
    int n = strlen(str);

    for (i = 0, j = n - 1; i < j; i++, j--) {
        temp = str[i];   
        str[i] = str[j];
        str[j] = temp;
    }
}

DesiredBase convertBase(char * baseNumber, Bases b, int base){
    DesiredBase d;
    d.otherBases = malloc(INPUT_WIDTH * sizeof(char));
    if (b.output == 10){
        d.baseTen = toBaseTen(baseNumber,b);
        return d;
    }
    int tempNum = toBaseTen(baseNumber, b);
    while(tempNum>=b.output){
        if (tempNum%b.output < 10){
            appendChar(d.otherBases, intToCharUnder10(tempNum%b.output));
            tempNum = floor(tempNum / b.output);
        }
        else{
            appendChar(d.otherBases, reverseHexmapValue(tempNum%b.output));
            tempNum = floor(tempNum / b.output);
        }
    }
    appendChar(d.otherBases,  intToCharUnder10(tempNum));
    reverseString(d.otherBases);
    return d;
}


int main(){
    Bases b;
    printf("***********************************************\n\n\n");
    printf("Welcome to this program to convert numbers from one"  
    " base to another.\n"
    "At this point in time you are only limited to bases 2 through to base 16 \n"
    "Kindly follow the prompt and you are good to go!\n"
    );

    while(programStatus){
        
        Bases bases = getInputAndOutputBase(b);
        printf("You wanna convert from base %d to base %d\n", bases.input, bases.output);
        getNumber(baseNumber);
        while (isBaseNumberValid(baseNumber, bases)==false){
            printf("The number you have entered is not a valid number in base %d\n", bases.input);
            flushInput(baseNumber);
            getNumber(baseNumber);
        }
        DesiredBase ans = convertBase(baseNumber, bases, bases.input);
        if (bases.output == 10){
            printf("%s (base %d) is ================> %d (base %d)\n", baseNumber, bases.input,  ans.baseTen, bases.output);
        }
        else{
            printf("%s (base %d) is ================> %s (base %d)\n", baseNumber, bases.input, ans.otherBases, bases.output);    
        }

        while (innerProgramStatus){
            //Determines if the program reruns or not.
            printf("\n\n Would you like to run the converter again? Press Y/N:\n");
            getInput(input);
            if ('y' == input[0] || 'Y' == input[0]){
                innerProgramStatus = false;
            }
            else if ('N' == input[0] || 'n' == input[0]){
                programStatus = false;
                innerProgramStatus = false;
            }else{
                printf("Please enter a valid response 'Y' or 'no'\n");
                flushInput(input);
            }
        }
        flushInput(baseNumber);
        flushInput(input);
    innerProgramStatus = true;
    }
        
    printf("************ Exiting Program **********************\n\n\n");
   return 0; 
}