#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int x, y, dist;
} Node;

typedef struct {
    Node data[MAX * MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int x, int y, int dist) {
    if (q->rear == MAX * MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->data[q->rear].x = x;
    q->data[q->rear].y = y;
    q->data[q->rear].dist = dist;
}

Node dequeue(Queue *q) {
    Node temp = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return temp;
}

int shortestPath(int mat[MAX][MAX], int n, int m) {
    if (mat[0][0] == 1 || mat[n-1][m-1] == 1) return -1;

    Queue q;
    initQueue(&q);
    enqueue(&q, 0, 0, 1);

    int row[] = {0, 1, 0, -1};
    int col[] = {1, 0, -1, 0};

    int visited[MAX][MAX] = {0};
    visited[0][0] = 1;

    while (!isEmpty(&q)) {
        Node temp = dequeue(&q);
        int x = temp.x, y = temp.y, dist = temp.dist;

        if (x == n-1 && y == m-1) return dist;

        for (int i = 0; i < 4; i++) {
            int newX = x + row[i];
            int newY = y + col[i];

            if (newX >= 0 && newX < n && newY >= 0 && newY < m && mat[newX][newY] == 0 && !visited[newX][newY]) {
                visited[newX][newY] = 1;
                enqueue(&q, newX, newY, dist + 1);
            }
        }
    }

    return -1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int mat[MAX][MAX];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("%d\n", shortestPath(mat, n, m));

    return 0;
}
