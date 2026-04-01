#include <stdio.h>
#include <string.h>

char stack[50];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int main() {
    char exp[50];
    printf("Enter expression: ");
    scanf("%s", exp);

    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else {
            if (top == -1) {
                printf("Invalid Expression\n");
                return 0;
            }
            pop();
        }
    }

    if (top == -1)
        printf("Valid Expression\n");
    else
        printf("Invalid Expression\n");
}