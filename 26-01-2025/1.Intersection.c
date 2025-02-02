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

struct Node* intersection(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node* temp1 = head1;
    while (temp1 != NULL) {
        struct Node* temp2 = head2;
        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                push(&result, temp1->data);
                break;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return result;
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    push(&head1, 5);
    push(&head1, 10);
    push(&head1, 15);
    push(&head2, 10);
    push(&head2, 30);
    struct Node* inter = intersection(head1, head2);
    while (inter != NULL) {
        printf("%d ", inter->data);
        inter = inter->next;
    }
    return 0;
}
