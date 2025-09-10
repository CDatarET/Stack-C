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

void pti(char pre[max]) {
    char op1[max];
    char op2[max];
    char infix[max * 2];

    for (int i = strlen(pre) - 1; i >= 0; i--) {
        if((pre[i] >= 'a' && pre[i] <= 'z') || (pre[i] >= '0' && pre[i] <= '9')){
            char operand[2] = {pre[i], '\0'};
            push(operand);
        }
        else{
            strcpy(op2, pop());
            strcpy(op1, pop());
            infix[0] = '\0';
            strcat(infix, "(");
            strcat(infix, op2);
            char operator[2] = {pre[i], '\0'};
            strcat(infix, operator);
            strcat(infix, op1);
            strcat(infix, ")");

            push(infix);
        }
    }

    printf("Infix expression: %s\n", stack[top]);
}

int main() {
    char pre[max];
    printf("Enter prefix expression: ");
    scanf("%s", pre);
    pti(pre);

    return 0;
}
