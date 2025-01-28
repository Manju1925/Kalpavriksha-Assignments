#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;
    return node;
}

void splitList(struct Node* source, struct Node** front, struct Node** back) {
    struct Node* slow = source;
    struct Node* fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

struct Node* mergeLists(struct Node* a, struct Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    struct Node* result = NULL;

    if (a->val <= b->val) {
        result = a;
        result->next = mergeLists(a->next, b);
    } else {
        result = b;
        result->next = mergeLists(a, b->next);
    }

    return result;
}

void mergeSort(struct Node** headRef) {
    struct Node* head = *headRef;
    if (head == NULL || head->next == NULL) return;

    struct Node* front;
    struct Node* back;

    splitList(head, &front, &back);

    mergeSort(&front);
    mergeSort(&back);

    *headRef = mergeLists(front, back);
}

void printList(struct Node* head) {
    struct Node* cur = head;
    while (cur != NULL) {
        printf(" %d", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    int n, val;
    struct Node* head = NULL;
    struct Node* tail = NULL;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Original linked list: ");
    printList(head);

    mergeSort(&head);

    printf("Sorted linked list: ");
    printList(head);

    return 0;
}
