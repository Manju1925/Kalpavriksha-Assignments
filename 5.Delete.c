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

struct Node* deleteKey(struct Node* head, int key){
    if (!head) return NULL;
    while (head && head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    while(current){
        if(current->data == key){
            struct Node* temp = current;
            prev->next = current->next;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
    return head;
}

void printList(struct Node* head){
    if (!head) {
        printf("NULL\n");
        return;
    }

    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int data, key;

    while(scanf("%d", &data) == 1){
        struct Node* newNode = createNode(data);

        if(!head){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        if(getchar() == '\n') break;
    }

    scanf("%d", &key);

    head = deleteKey(head, key);
    printList(head);

    return 0;
}
