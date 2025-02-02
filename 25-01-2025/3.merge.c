#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* merge(struct Node* l1, struct Node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    if (l1->data < l2->data) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    struct Node* l1 = NULL;
    struct Node* l2 = NULL;
    struct Node* result = NULL;

    l1 = (struct Node*)malloc(sizeof(struct Node));
    l1->data = 1;
    l1->next = (struct Node*)malloc(sizeof(struct Node));
    l1->next->data = 3;
    l1->next->next = (struct Node*)malloc(sizeof(struct Node));
    l1->next->next->data = 5;
    l1->next->next->next = NULL;

    l2 = (struct Node*)malloc(sizeof(struct Node));
    l2->data = 2;
    l2->next = (struct Node*)malloc(sizeof(struct Node));
    l2->next->data = 4;
    l2->next->next = (struct Node*)malloc(sizeof(struct Node));
    l2->next->next->data = 6;
    l2->next->next->next = NULL;

    result = merge(l1, l2);
    
    printf("Merged List: ");
    printList(result);
    
    return 0;
}
