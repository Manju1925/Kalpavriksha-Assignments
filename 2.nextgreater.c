#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int data;
    struct Stack* next;
} Stack;

void push(Stack** top, int value) {
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

int pop(Stack** top) {
    if (*top == NULL) return -1;
    Stack* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

int isEmpty(Stack* top) {
    return top == NULL;
}

void nextGreaterElement(int arr[], int n) {
    int nge[n];
    Stack* stack = NULL;

    for (int i = n - 1; i >= 0; i--) {
        while (!isEmpty(stack) && stack->data <= arr[i]) {
            pop(&stack);
        }
        
        nge[i] = isEmpty(stack) ? -1 : stack->data;
        
        push(&stack, arr[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", arr[i], nge[i]);
    }
}

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Next Greater Elements:\n");
    nextGreaterElement(arr, n);

    return 0;
}
