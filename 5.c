#include <stdio.h>
#include <ctype.h>

int stack[50], top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char exp[50];
    printf("Enter postfix: ");
    scanf("%s", exp);

    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i]))
            push(exp[i] - '0');
        else {
            int a = pop();
            int b = pop();

            switch (exp[i]) {
                case '+': push(b + a); break;
                case '-': push(b - a); break;
                case '*': push(b * a); break;
                case '/': push(b / a); break;
            }
        }
    }

    printf("Result = %d\n", pop());
}