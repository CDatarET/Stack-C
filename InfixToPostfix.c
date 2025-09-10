#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 50

char stack[max][max];
int top = -1;

int isFull() {
    return (top == max - 1);
}

int isEmpty() {
    return (top == -1);
}

void push(char *str) {
    if (!isFull()) {
        top++;
        strcpy(stack[top], str);
    }
    else{
        printf("Stack Overflow Error. Terminating...\n");
        abort();
    }
}

char* pop() {
    if (!isEmpty()) {
        return stack[top--];
    }
    else{
        printf("Stack Underflow Error. Terminating...\n");
        abort();
    }
}

int precedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

void infixToPostfix(char infix[max]) {
    char postfix[max] = "";
    char temp[2];
    char topOp[2];
    int i;

    for(i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If operand, add to postfix
        if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            temp[0] = ch;
            temp[1] = '\0';
            strcat(postfix, temp);
        }
        else if(ch == '(') {
            temp[0] = ch;
            temp[1] = '\0';
            push(temp);
        }
        else if(ch == ')') {
            while(!isEmpty() && strcmp(stack[top], "(") != 0) {
                strcat(postfix, pop());
            }
            if(!isEmpty() && strcmp(stack[top], "(") == 0) {
                pop(); // remove '(' from stack
            }
        }
        else { // operator
            while(!isEmpty() && precedence(stack[top][0]) >= precedence(ch)) {
                strcat(postfix, pop());
            }
            temp[0] = ch;
            temp[1] = '\0';
            push(temp);
        }
    }

    while(!isEmpty()) {
        strcat(postfix, pop());
    }

    printf("Postfix expression: %s\n", postfix);
}

int main() {
    char infix[max];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}
