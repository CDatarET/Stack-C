#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 50

char stack[max];
int top = -1;

int isFull() {
    return (top == max - 1);
}

int isEmpty() {
    return (top == -1);
}

void push(char c) {
    if (!isFull()) {
        top++;
        stack[top] = c;
    }
    else{
        printf("\nStack Overflow Error. Terminating...\n");
        abort();
    }
}

char pop() {
    if (!isEmpty()) {
        return stack[top--];
    }
    else{
        printf("\nStack Underflow Error. Terminating...\n");
        abort();
    }
}

int isp(char c) {
    switch(c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

int icp(char c) {
    switch(c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 4;
        case '(':
        case ')':
            return 5;
    }
    return 0;
}

void itp(char infix[max]) {
    for(int i = 0; infix[i] != '\0'; i++){
        if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= '0' && infix[i] <= '9')){
            printf("%c", infix[i]);
        }
        else{
            if(infix[i] == '('){
                push('(');
            }
            else if(infix[i] == ')'){
                while(stack[top] != '('){
                    printf("%c", pop());
                }
                char t = pop();//clear '(' from stack
            }
            else{
                if(isEmpty()){
                    push(infix[i]);
                }
                else{
                    if(isp(stack[top]) >= icp(infix[i])){
                        while(isp(stack[top]) >= icp(infix[i]) && !isEmpty()){
                            printf("%c", pop());
                        } 
                    }
                    push(infix[i]);
                }
                
            }
        }
    }

    while(!isEmpty()){
        printf("%c", pop());
    }
    printf("\n");
}

int main() {
    char infix[max];
    printf("Enter Infix expression: ");
    scanf("%s", infix);
    itp(infix);
    return 0;
}
