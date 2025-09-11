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
    int i = strlen(infix) - 1;
    int j = 0;
    char prefix[max];
    while(i >= 0){
        if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= '0' && infix[i] <= '9')){
            prefix[j] = infix[i];
            j++;
        }
        else{
            if(infix[i] == ')'){
                push(')');
            }
            else if(infix[i] == '('){
                while(stack[top] != ')'){
                    prefix[j] = pop();
                    j++;
                }
                char t = pop(); //clear ')' from stack
            }
            else{
                if(isEmpty()){
                    push(infix[i]);
                }
                else{
                    if(isp(stack[top]) > icp(infix[i])){
                        while(!isEmpty() && isp(stack[top]) >= icp(infix[i])){
                            prefix[j] = pop();
                            j++;
                        }
                    }
                    push(infix[i]);
                }
            }
        }
        i--;
    }

    while(!isEmpty()){
        prefix[j] = pop();
        j++;
    }
    
    for(int i = j - 1; i >= 0; i--){
        printf("%c", prefix[i]);
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
