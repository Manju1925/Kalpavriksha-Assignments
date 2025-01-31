#include <stdio.h>
#include <stdlib.h>

#define MAX 25

int stack[MAX], top = -1;

void push(int ele) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = ele;
}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return;
    }
    top--;
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
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d-", stack[i]);
        }
        printf("\n");
    }
}

void size() {
    printf("%d\n", top + 1);
}

int main() {
    int choice, ele;

    while (1) {
        printf("1.Push 2.Pop 3.Peek 4.Display 5.Size 6.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                push(ele);
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
                size();
                break;
            case 6:
                return 0;
            default:
                printf("Enter a valid option\n");
        }
    }
}
