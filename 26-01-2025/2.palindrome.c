#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int isPalindrome(struct Node* head) {
    struct Node *slow = head, *fast = head, *prev = NULL, *temp = NULL;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        temp = slow;
        slow = slow->next;
        temp->next = prev;
        prev = temp;
    }
    if (fast != NULL) slow = slow->next;
    while (prev != NULL && slow != NULL) {
        if (prev->data != slow->data) return 0;
        prev = prev->next;
        slow = slow->next;
    }
    return 1;
}

int main() {
    struct Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    
    if (isPalindrome(head)) 
        printf("The linked list is a palindrome.\n");
    else 
        printf("The linked list is not a palindrome.\n");
    return 0;
}
