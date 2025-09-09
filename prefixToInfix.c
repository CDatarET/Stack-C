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
    char infix[max];

    for (int i = 0; pre[i] != '\0'; i++) {
        if((pre[i] >= 'a' && pre[i] <= 'z') || (pre[i] >= '0' && pre[i] <= '9')){
            char operand[2] = {pre[i], '\0'};
            push(operand);
        }
        else if (pre[i] == '+' || pre[i] == '-' || pre[i] == '*' || pre[i] == '/' || pre[i] == '%') {
            strcpy(op1, pop());
            strcpy(op2, pop());
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

    if (!isEmpty()) {
        printf("Infix expression: %s\n", stack[top]);
    }
    else {
        printf("Invalid postfix expression.\n");
    }
}

int main() {
    char pre[max];
    printf("Enter prefix expression: ");
    scanf("%s", pre);
    pti(pre);

    return 0;
}
