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

void swap(struct Node* a, struct Node* b) {
    int temp = a->val;
    a->val = b->val;
    b->val = temp;
}

struct Node* partition(struct Node* head, struct Node* end, struct Node** newHead, struct Node** newEnd) {
    struct Node* pivot = end;
    struct Node* prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->val < pivot->val) {
            if (*newHead == NULL) {
                *newHead = cur;
            }
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) {
                prev->next = cur->next;
            }
            struct Node* temp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }

    if (*newHead == NULL) {
        *newHead = pivot;
    }

    *newEnd = tail;

    return pivot;
}

struct Node* quickSortRecur(struct Node* head, struct Node* end) {
    if (!head || head == end) {
        return head;
    }

    struct Node *newHead = NULL, *newEnd = NULL;

    struct Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        struct Node* temp = newHead;
        while (temp->next != pivot) {
            temp = temp->next;
        }
        temp->next = NULL;

        newHead = quickSortRecur(newHead, temp);

        temp = newHead;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

void quickSort(struct Node** headRef) {
    *headRef = quickSortRecur(*headRef, getTail(*headRef));
}

struct Node* getTail(struct Node* head) {
    while (head != NULL && head->next != NULL) {
        head = head->next;
    }
    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
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

    quickSort(&head);

    printf("Sorted linked list: ");
    printList(head);

    return 0;
}
