#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 1000

// Stack implementation
typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void push(Stack* stack, int value) {
    if (stack->top < MAX_STACK_SIZE - 1) {
        stack->data[++stack->top] = value;
    }
}

void pop(Stack* stack) {
    if (stack->top >= 0) {
        stack->top--;
    }
}

int top(Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top];
    }
    return -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void nextLargerElement(int arr[], int n, int result[]) {
    Stack stack;
    stack.top = -1;
    
    for (int i = n - 1; i >= 0; i--) {
        while (!isEmpty(&stack) && top(&stack) <= arr[i]) {
            pop(&stack);
        }
        
        result[i] = isEmpty(&stack) ? -1 : top(&stack);
        push(&stack, arr[i]);
    }
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result[n];
    
    nextLargerElement(arr, n, result);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    return 0;
}
