#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 50

char stack[max][max];
int top = -1;

int isEmpty(){
    return(top == -1);
}

int isFull(){
    return(top == max - 1);
}

char* pop(){
    if(!isEmpty()){
        return(stack[top--]);
    }
    else{
        printf("Stack Underflow Error! Terminating...\n");
        abort();
    }
}

void push(char* str){
    if(isFull()){
        printf("Stack Overflow Error! Terminating...\n");
        abort();
    }
    top++;
    strcpy(stack[top], str);
}

void itp(char in[max]){
    char op1[max];
    char op2[max];
    int i = 0;
    
    while(in[i] != '\0'){
        //fill in later
        i++;
    }
    printf("\n");
}

int main() {
    char in[max];
    printf("Enter infix expression: ");
    scanf("%s", in);
    itp(in);
    
    return 0;
}
