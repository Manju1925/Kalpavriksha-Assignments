#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Stack {
    char arr[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char c) {
    if (stack->top < MAX_SIZE - 1) {
        stack->arr[++(stack->top)] = c;
    } else {
        printf("Stack Overflow\n");
    }
}

char pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[(stack->top)--];
    } else {
        printf("Stack Underflow\n");
        return '\0';
    }
}

char peek(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->arr[stack->top];
    } else {
        printf("Stack is empty\n");
        return '\0';
    }
}

void type(Stack* mainStack, Stack* redoStack, char c) {
    push(mainStack, c);
    initStack(redoStack);
}

void undo(Stack* mainStack, Stack* redoStack) {
    if (!isEmpty(mainStack)) {
        char c = pop(mainStack);
        push(redoStack, c);
    } else {
        printf("Nothing to undo\n");
    }
}

void redo(Stack* mainStack, Stack* redoStack) {
    if (!isEmpty(redoStack)) {
        char c = pop(redoStack);
        push(mainStack, c);
    } else {
        printf("Nothing to redo\n");
    }
}

void displayText(Stack* mainStack) {
    if (isEmpty(mainStack)) {
        printf("Text is empty\n");
        return;
    }

    for (int i = 0; i <= mainStack->top; i++) {
        printf("%c", mainStack->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack mainStack, redoStack;
    initStack(&mainStack);
    initStack(&redoStack);

    type(&mainStack, &redoStack, 'H');
    type(&mainStack, &redoStack, 'e');
    type(&mainStack, &redoStack, 'l');
    type(&mainStack, &redoStack, 'l');
    type(&mainStack, &redoStack, 'o');

    printf("Text after typing: ");
    displayText(&mainStack);

    undo(&mainStack, &redoStack);
    printf("Text after undo: ");
    displayText(&mainStack);

    redo(&mainStack, &redoStack);
    printf("Text after redo: ");
    displayText(&mainStack);

    return 0;
}
