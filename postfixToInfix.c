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
    } else {
        printf("Stack Overflow\n");
    }
}

char* pop() {
    if (!isEmpty()) {
        return stack[top--];
    } else {
        printf("Stack Empty\n");
        return "";
    }
}

void pti(char post[max]) {
    char op1[max];
    char op2[max];
    char infix[max];

    for (int i = 0; post[i] != '\0'; i++) {
        if((post[i] >= 'a' && post[i] <= 'z') || (post[i] >= '0' && post[i] <= '9')){
            char operand[2] = {post[i], '\0'};
            push(operand);
        } else if (post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/' || post[i] == '%') {
            strcpy(op1, pop());
            strcpy(op2, pop());
            infix[0] = '\0';
            strcat(infix, "(");
            strcat(infix, op2);
            char operator[2] = {post[i], '\0'};
            strcat(infix, operator);
            strcat(infix, op1);
            strcat(infix, ")");

            push(infix);
        }
    }

    if (!isEmpty()) {
        printf("Infix expression: %s\n", stack[top]);
    } else {
        printf("Invalid postfix expression.\n");
    }
}

int main() {
    char post[max];
    printf("Enter postfix expression: ");
    scanf("%s", post);
    pti(post);

    return 0;
}
