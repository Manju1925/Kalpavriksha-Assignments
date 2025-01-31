#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 1000000

typedef struct Node {
    char *state;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

void push(Stack *stack, const char *s) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->state = strdup(s);
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(Stack *stack, char *s) {
    if (stack->top) {
        Node *temp = stack->top;
        strcpy(s, temp->state);
        stack->top = temp->next;
        free(temp->state);
        free(temp);
    }
}

void freeStack(Stack *stack) {
    while (stack->top) {
        Node *temp = stack->top;
        stack->top = temp->next;
        free(temp->state);
        free(temp);
    }
}

int main() {
    int q;
    scanf("%d", &q);

    char S[MAX_LEN + 1] = "";
    Stack history = {NULL};

    for (int i = 0; i < q; i++) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            char W[MAX_LEN + 1];
            scanf("%s", W);
            push(&history, S);
            strcat(S, W);
        } 
        else if (op == 2) {
            int k;
            scanf("%d", &k);
            push(&history, S);
            S[strlen(S) - k] = '\0';
        } 
        else if (op == 3) {
            int k;
            scanf("%d", &k);
            printf("%c\n", S[k - 1]);
        } 
        else if (op == 4) {
            pop(&history, S);
        }
    }

    freeStack(&history);
    return 0;
}