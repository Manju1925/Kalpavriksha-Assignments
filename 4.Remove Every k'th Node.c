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

struct Node* removeKthNode(struct Node* head, int k){
    if(!head || k == 0){
        return head;
    }

    struct Node* current = head;
    struct Node* prev = NULL;
    int count = 1;

    while(current){
        if(count % k == 0){
            struct Node* temp = current;
            if(prev){
                prev->next = current->next;
            } else {
                head = current->next;
            }
            current = current->next;
            free(temp);
        }else{
            prev = current;
            current = current->next;
        }
        count++;
    }
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
    int data,k;

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

    scanf("%d", &k);

    head = removeKthNode(head, k);
    printList(head);

    return 0;
}
