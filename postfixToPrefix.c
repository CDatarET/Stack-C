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

void postToPre(char post[max]){
    char op1[max];
    char op2[max];
    int i = 0;
    
    while(post[i] != '\0'){
        if((post[i] >= '0' && post[i] <= '9') || (post[i] >= 'a' && post[i] <= 'z')){
            char t[] = {post[i], '\0'};
            push(t);
        }
        else{
            strcpy(op2, pop());
            strcpy(op1, pop());
            char t[max];
            t[0] = post[i];
            t[1] = '\0';

            char temp[max];
            strcpy(temp, t);
            strcat(temp, op1);
            strcat(temp, op2);
            
            push(temp);
        }
        i++;
    }
    printf("%s\n", pop());
}

int main() {
    char post[max];
    printf("Enter postfix expression: ");
    scanf("%s", post);
    postToPre(post);
    
    return 0;
}
