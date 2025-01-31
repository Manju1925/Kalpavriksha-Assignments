#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* createNode(int data) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(struct StackNode* top) {
    return top == NULL;
}

void push(struct StackNode** top, int data) {
    struct StackNode* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

int pop(struct StackNode** top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct StackNode* temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

int peek(struct StackNode* top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

void printStack(struct StackNode* top) {
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

int main() {
    struct StackNode* stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    
    printStack(stack);
    
    printf("Popped: %d\n", pop(&stack));
    printf("Top element: %d\n", peek(stack));
    
    printStack(stack);

    return 0;
}
