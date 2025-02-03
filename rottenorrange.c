#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int x, y;
} Pair;

typedef struct {
    Pair data[MAX * MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int x, int y) {
    if (q->rear == MAX * MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->data[q->rear].x = x;
    q->data[q->rear].y = y;
}

Pair dequeue(Queue *q) {
    Pair p = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return p;
}

int orangesRotting(int mat[MAX][MAX], int n, int m) {
    Queue q;
    initQueue(&q);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 2) {
                enqueue(&q, i, j);
            }
        }
    }

    int count = -1;
    int row[] = {0, 1, 0, -1};
    int col[] = {1, 0, -1, 0};

    while (!isEmpty(&q)) {
        int k = q.rear - q.front + 1;
        count++;
        for (int y = 0; y < k; y++) {
            Pair p = dequeue(&q);
            int i = p.x, j = p.y;

            for (int x = 0; x < 4; x++) {
                int r = i + row[x];
                int c = j + col[x];

                if (r >= 0 && r < n && c >= 0 && c < m && mat[r][c] == 1) {
                    mat[r][c] = 2;
                    enqueue(&q, r, c);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) {
                return -1;
            }
        }
    }

    return (count == -1) ? 0 : count;
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

    printf("%d\n", orangesRotting(mat, n, m));

    return 0;
}
