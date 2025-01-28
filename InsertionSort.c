#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* insrt(struct Node* newN, struct Node* sorted) {
    if (sorted == NULL || sorted->val >= newN->val) {
        newN->next = sorted;
        sorted = newN;
    }
    else {
        struct Node* cur = sorted;
        while (cur->next != NULL && cur->next->val < newN->val) {
            cur = cur->next;
        }
        newN->next = cur->next;
        cur->next = newN;
    }
    return sorted;
}

struct Node* insrtSort(struct Node* head){
    struct Node* sorted = NULL;
    struct Node* cur = head;
    while (cur != NULL) {
        struct Node* nxt = cur->next;
        sorted = insrt(cur, sorted);
        cur = nxt;
    }
    return sorted;
}

void prntList(struct Node* head){
    struct Node* cur = head;
    while (cur != NULL) {
        printf(" %d", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

struct Node* newN(int val){
    struct Node* node =(struct Node*)malloc(sizeof(struct Node));
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
    for (int i = 0; i < n; ++i){
        scanf("%d", &val);
        struct Node* newNode = newN(val);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Original linked list: ");
    prntList(head);

    head = insrtSort(head);

    printf("Sorted linked list: ");
    prntList(head);

    return 0;
}
