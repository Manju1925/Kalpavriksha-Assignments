#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};


struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* reverseLinkedList(struct Node* head){
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while(current != NULL){
        next = current->next; 
        current->next = prev; 
        prev = current;      
        current = next;    
    }
    return prev;
}


void printList(struct Node* head){
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int data;


    while (scanf("%d", &data) != EOF){
        struct Node* newNode = createNode(data);

        if (head == NULL){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = reverseLinkedList(head);

    printList(head);

    return 0;
}
