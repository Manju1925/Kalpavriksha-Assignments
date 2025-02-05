#include <stdio.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top == MAX - 1) return;
    stack[++top] = ch;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isValid(char input[]) {
    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1 || !isMatchingPair(pop(), ch)) {
                return 0;
            }
        }
    }
    return (top == -1);
}

int main() {
    char input[MAX];
    scanf("%[^\n]", input);
    getchar();

    if (isValid(input)) {
        printf("Valid\n");
    } else {
        printf("Not Valid\n");
    }
    
    return 0;
}
