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

struct Node* getMiddle(struct Node* start, struct Node* end) {
    if (start == NULL) return NULL;
    struct Node* slow = start;
    struct Node* fast = start->next;

    while (fast != end) {
        fast = fast->next;
        if (fast != end) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

int binarySearch(struct Node* head, int key) {
    struct Node* start = head;
    struct Node* end = NULL;

    while (start != end) {
        struct Node* mid = getMiddle(start, end);

        if (mid == NULL) {
            return -1;
        }

        if (mid->val == key) {
            return 1;
        } else if (mid->val < key) {
            start = mid->next;
        } else {
            end = mid;
        }
    }

    return -1;
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
    int n, val, key;
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

    printf("Enter the value to search: ");
    scanf("%d", &key);

    int result = binarySearch(head, key);

    if (result == 1) {
        printf("Value %d found in the linked list.\n", key);
    } else {
        printf("Value %d not found in the linked list.\n", key);
    }

    return 0;
}
