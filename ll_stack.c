#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (!top) {
        printf("Stack underflow\n");
        return;
    }
    Node* temp = top;
    top = top->next;
    free(temp);
}

void peek() {
    if (!top) {
        printf("No elements\n");
    } else {
        printf("%d\n", top->data);
    }
}

void display() {
    if (!top) {
        printf("No elements\n");
        return;
    }
    Node* temp = top;
    while (temp) {
        printf("%d-", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void stackSize() {
    int count = 0;
    Node* temp = top;
    while (temp) {
        count++;
        temp = temp->next;
    }
    printf("%d\n", count);
}

int main() {
    int choice, value;
    for (;;) {
        printf("1.Push 2.Pop 3.Peek 4.Display 5.Size 6.Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &value);
                push(value);
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
                stackSize();
                break;
            case 6:
                return 0;
            default:
                printf("Enter a valid option\n");
        }
    }
}
