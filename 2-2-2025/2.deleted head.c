#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void deleteNode(Node* del_node) {
    if (del_node == NULL || del_node->next == NULL) {
        return;
    }

    Node* temp = del_node->next;
    del_node->data = temp->data;
    del_node->next = temp->next;
    free(temp);
}


Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    
    printf("Original List: ");
    printList(head);
    
    deleteNode(head->next); 
    
    printf("After Deletion: ");
    printList(head);
    
    return 0;
}
