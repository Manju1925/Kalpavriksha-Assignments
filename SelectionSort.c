#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

void swap(struct Node* a, struct Node* b) {
    int temp = a->val;
    a->val = b->val;
    b->val = temp;
}

struct Node* selectionSort(struct Node* head) {
    struct Node* curr = head;

    while (curr != NULL) {
        struct Node* min = curr;
        struct Node* nxt = curr->next;

        while (nxt != NULL) {
            if (min->val > nxt->val) {
                min = nxt;
            }
            nxt = nxt->next;
        }

        if (min != curr) {
            swap(curr, min);
        }

        curr = curr->next;
    }
    
    return head;
}

void printList(struct Node* head) {
    struct Node* cur = head;
    while (cur != NULL) {
        printf(" %d", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

struct Node* createNode(int val) { 
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;
    return node;
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
        struct Node* newN = createNode(val);
        if (head == NULL) {
            head = newN;
            tail = newN;
        } else {
            tail->next = newN;
            tail = newN;
        }
    }

    printf("Original linked list: ");
    printList(head);

    head = selectionSort(head);

    printf("Sorted linked list: ");
    printList(head);

    return 0;
}
