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

void preToPost(char pre[max]){
    char op1[max];
    char op2[max];
    int i = strlen(pre) - 1;
    
    while(i >= 0){
        if((pre[i] >= '0' && pre[i] <= '9') || (pre[i] >= 'a' && pre[i] <= 'z')){
            char t[] = {pre[i], '\0'};
            push(t);
        }
        else{
            strcpy(op1, pop());
            strcpy(op2, pop());
            char t[max];
            t[0] = pre[i];
            t[1] = '\0';

            char temp[max];
            strcpy(temp, op1);
            strcat(temp, op2);
            strcat(temp, t);
            push(temp);
        }
        i--;
    }
    printf("%s\n", stack[top]);
}

int main() {
    char pre[max];
    printf("Enter pre expression: ");
    scanf("%s", pre);
    preToPost(pre);
    
    return 0;
}
