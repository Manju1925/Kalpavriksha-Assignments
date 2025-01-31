#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* reverseIterative(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

struct Node* reverseRecursive(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

int main() {
    struct Node* head = NULL;
    head = insert(head, 5);
    head = insert(head, 4);
    head = insert(head, 3);
    head = insert(head, 2);
    head = insert(head, 1);

    printList(head);
    head = reverseIterative(head);
    printList(head);

    head = reverseRecursive(head);
    printList(head);

    return 0;
}
