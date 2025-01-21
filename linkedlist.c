#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head=NULL;

struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value){
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value){
    struct Node* newNode = createNode(value);
    if(head == NULL){
        head = newNode;
    }else {
        struct Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtPosition(int position, int value){
    if (position< 1){
        printf("Invalid position\n");
        return;
    }
    struct Node* newNode = createNode(value);
    if(position == 1){
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    for(int i = 1; temp != NULL && i < position - 1; i++){
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
    }else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void display(){
    if (head == NULL){
        printf("NULL\n");
    }else{
        struct Node* temp = head;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void updateAtPosition(int position, int newValue){
    if(position < 1){
        printf("Invalid position\n");
        return;
    }
    struct Node* temp = head;
    for(int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Invalid position\n");
    }else{
        temp->data = newValue;
    }
}

void deleteAtBeginning(){
    if(head == NULL) {
        printf("Invalid position\n");
    }else{
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

void deleteAtEnd(){
    if(head == NULL){
        printf("Invalid position\n");
    }else if(head->next == NULL) {
        free(head);
        head = NULL;
    }else{
        struct Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void deleteAtPosition(int position){
    if (position < 1 || head == NULL){
        printf("Invalid position\n");
    }else if (position == 1) {
        deleteAtBeginning();
    }else {
        struct Node* temp = head;
        for(int i = 1; temp != NULL && i < position - 1; i++){
            temp = temp->next;
        }
        if(temp == NULL || temp->next == NULL){
            printf("Invalid position\n");
        } else {
            struct Node* toDelete = temp->next;
            temp->next = temp->next->next;
            free(toDelete);
        }
    }
}

int main() {
    int n, operation, value, position;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &operation);
        switch (operation){
            case 1:
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 2:
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 3:
                scanf("%d %d", &position, &value);
                insertAtPosition(position, value);
                break;
            case 4:
                display();
                break;
            case 5:
                scanf("%d %d", &position, &value);
                updateAtPosition(position, value);
                break;
            case 6:
                deleteAtBeginning();
                break;
            case 7:
                deleteAtEnd();
                break;
            case 8:
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            default:
                printf("Invalid operation\n");
        }
    }
    return 0;
}
