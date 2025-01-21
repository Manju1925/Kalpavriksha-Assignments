#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* removeMiddle(struct Node* head){
    if(!head || !head->next) {
        return NULL;
    }

    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* prev = NULL;

    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }


    if(prev){
        prev->next = slow->next;
    }

    free(slow);
    return head;
}


void printList(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int data;


    while(scanf("%d", &data) != EOF){
        struct Node* newNode = createNode(data);

        if(!head){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = removeMiddle(head);
    printList(head);

    return 0;
}
