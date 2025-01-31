#include <stdio.h>
#include <stdlib.h>

#define SIZE 25

int stackA[SIZE], stackB[SIZE], topA = -1, topB = -1;

void push(int stackNum, int val) {
    if (stackNum == 1) {
        if (topA == SIZE - 1) {
            printf("Stack A overflow\n");
            return;
        }
        stackA[++topA] = val;
    } else if (stackNum == 2) {
        if (topB == SIZE - 1) {
            printf("Stack B overflow\n");
            return;
        }
        stackB[++topB] = val;
    }
}

int pop(int stackNum) {
    if (stackNum == 1) {
        if (topA == -1) {
            printf("Stack A underflow\n");
            return -1;
        }
        return stackA[topA--];
    } else if (stackNum == 2) {
        if (topB == -1) {
            printf("Stack B underflow\n");
            return -1;
        }
        return stackB[topB--];
    }
    return -1;
}

void peek() {
    if (topA == -1) {
        printf("Queue is empty\n");
    } else {
        printf("%d\n", stackA[topA]);
    }
}

void display() {
    if (topA == -1) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = topA; i >= 0; i--) {
        printf("%d ", stackA[i]);
    }
    printf("\n");
}

void enqueue(int val) {
    if (topA == SIZE - 1) {
        printf("Queue overflow\n");
        return;
    }
    while (topA != -1) {
        push(2, pop(1));
    }
    push(1, val);
    while (topB != -1) {
        push(1, pop(2));
    }
}

void queueSize() {
    printf("%d\n", topA + 1);
}

int main() {
    int option, value;

    for (;;) {
        printf("1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Size 6.Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                pop(1);
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
