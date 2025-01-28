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

int detectCycle(struct Node* head) {
    if (head == NULL) return 0;
    
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return 1;
        }
    }

    return 0;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->next;
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

    printf("Linked List: ");
    printList(head);

    int result = detectCycle(head);

    if (result == 1) {
        printf("Cycle detected in the linked list.\n");
    } else {
        printf("No cycle detected in the linked list.\n");
    }

    return 0;
}
