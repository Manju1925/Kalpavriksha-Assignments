#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

int getSize(struct Node *head) {
    int cnt = 0;
    struct Node *cur = head;
    
    while (cur != NULL) {
        cnt++;
        cur = cur->next;
    }
    return cnt;
}

struct Node *bubSort(struct Node *head) {
    struct Node *cur = head;
    int sz = getSize(head);
    int itr = 0;
    int swapped;

    while (itr < sz) {
        struct Node *cmp = head;
        struct Node *prev = NULL;
        swapped = 0;

        while (cmp->next != NULL) {
            struct Node *nxt = cmp->next;

            if (cmp->val > nxt->val) {
                swapped = 1;
                
                if (cmp == head) {
                    cmp->next = nxt->next;
                    nxt->next = cmp;
                    head = nxt;
                } else {
                    cmp->next = nxt->next;
                    nxt->next = cmp;
                    prev->next = nxt;
                    prev = nxt;
                }
                continue;
            }

            prev = cmp;
            cmp = cmp->next;
        }

        if (!swapped) {
            break;
        }
        itr++;
    }
    
    return head;
}

void printList(struct Node *head) {
    struct Node *cur = head;
    
    while (cur != NULL) {
        printf("%d -> ", cur->val);
        cur = cur->next;
    }
    printf("NULL\n");
}

struct Node *newNode(int val) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;
    return node;
}

void appendNode(struct Node **head, int val) {
    struct Node *node = newNode(val);
    
    if (*head == NULL) {
        *head = node;
        return;
    }
    
    struct Node *cur = *head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = node;
}

int main() {
    struct Node *head = NULL;
    int n, val;

    printf("Enter the number of nodes in the list: ");
    scanf("%d", &n);

    printf("Enter the node values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        appendNode(&head, val);
    }

    printf("Initial Linked List:\n");
    printList(head);

    head = bubSort(head);

    printf("Sorted Linked List:\n");
    printList(head);

    return 0;
}
