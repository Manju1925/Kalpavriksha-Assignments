#include <stdio.h>
#include <stdlib.h>

#define SIZE 25

int stack[SIZE], top = -1;

void push(int val) {
    if (top == SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = val;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

void peek() {
    if (top == -1) {
        printf("No elements\n");
    } else {
        printf("%d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("No elements\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d-", stack[i]);
    }
    printf("\n");
}

void insertAtBottom(int val) {
    if (top == -1) {
        push(val);
        return;
    }
    int temp = pop();
    insertAtBottom(val);
    push(temp);
}

void enqueue(int val) {
    if (top == SIZE - 1) {
        printf("Queue overflow\n");
        return;
    }
    insertAtBottom(val);
}

void queueSize() {
    printf("%d\n", top + 1);
}

int main() {
    int option, val;

    for (;;) {
        printf("1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Size 6.Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                queueSize();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
