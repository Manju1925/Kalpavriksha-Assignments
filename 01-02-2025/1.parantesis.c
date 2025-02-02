#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 1000

// Stack implementation
typedef struct {
    char data[MAX_STACK_SIZE];
    int top;
} Stack;

void push(Stack* stack, char ch) {
    if (stack->top < MAX_STACK_SIZE - 1) {
        stack->data[++stack->top] = ch;
    }
}

void pop(Stack* stack) {
    if (stack->top >= 0) {
        stack->top--;
    }
}

char top(Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top];
    }
    return '\0';
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

bool isParenthesisBalanced(const char* s) {
    Stack stack;
    stack.top = -1;
    
    for (int i = 0; i < strlen(s); i++) {
        char ch = s[i];
        
        if (ch == ')' || ch == '}' || ch == ']') {
            if (!isEmpty(&stack) && ((ch == ')' && top(&stack) == '(') ||
                                     (ch == '}' && top(&stack) == '{') ||
                                     (ch == ']' && top(&stack) == '['))) {
                pop(&stack);
            } else {
                return false;
            }
        } else if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        }
    }
    
    return isEmpty(&stack);
}

int main() {
    char test[] = "{[()]}";
    if (isParenthesisBalanced(test)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }
    return 0;
}
