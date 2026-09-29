#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int stack[100];
int top=-1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main(void) {
    char exp[100];
    int a,b,result;

    printf("Enter postfix expreesion to be evaluated: ");
    scanf("%s", exp);

    for (int i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            push(exp[i]-'0');
        }
        else {
            b=pop();
            a=pop();

            switch (exp[i]) {
                case '+': result = a+b; break;
                case '-': result = a-b; break;
                case '*': result = a*b; break;
                case '/': result = a/b; break;
                case '^':
                    result = 1;
                    for (int j = 0; j<b; j++)
                        result *= a;
                    break;
            }
            push(result);
        }
    }
    printf("Result = %d\n", result);
    return 0;
}