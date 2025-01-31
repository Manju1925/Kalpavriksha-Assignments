#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node *front = NULL, *rear = NULL;

int isEmpty() {
    return front == NULL;
}

void enqueue(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = front;
    front = front->next;
    printf("Dequeued: %d\n", temp->data);
    free(temp);
    if (!front) {
        rear = NULL;
    }
}

void peek() {
    if (!isEmpty()) {
        printf("%d\n", front->data);
    } else {
        printf("Queue is empty\n");
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = front;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void queueSize() {
    int count = 0;
    Node* temp = front;
    while (temp) {
        count++;
        temp = temp->next;
    }
    printf("%d\n", count);
}

int main() {
    int choice, value;

    for (;;) {
        printf("1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Size 6.Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
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
