#include <stdio.h>
#include <stdlib.h>
#include<math.h>

typedef struct queue
{
    int **arr;
    int size;
    int front;
    int rear;
    int bits;
} queue;

void queueInit(queue *q, int n)
{
    q->size = n;
    q->arr = (int **)malloc(n * sizeof(int *));
    q->front = -1;
    q->rear = -1;
    q->bits = (int)(log2(n) + 1) ;
}

void push(queue *q, int *data)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = q->rear = 0;
        q->arr[q->rear] = (int*)malloc(q->bits * sizeof(int));
        for(int i=0; i<q->bits ; i++){
            q->arr[q->rear][i] = data[i];
        }
        return;
    }
    else
    {
        q->rear++;
        // q->arr[q->rear] = data;
        q->arr[q->rear] = (int*)malloc(q->bits  * sizeof(int));
        for(int i=0; i<q->bits ; i++){
            q->arr[q->rear][i] = data[i];
        }
        return;
    }
}

void display(queue *q)
{
    if (q->front == -1 || q->front > q->rear)
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++)
    {
        for (int j = 0; j < q->bits ; j++)
        {
            printf("%d", q->arr[i][j]);
        }
        printf(" ");
    }
    printf("\n");
}

void binary(queue *q, int n)
{
    int num;
    int *arr = (int *)malloc(q->bits * sizeof(int));
    for (int k = 0; k < q->bits; k++) {
            arr[k] = 0;  
        }
    for (int i = 1; i <= n; i++)
    {
        num = i;
        int j = q->bits -1;
        while (num > 0)
        {
            arr[j--] = num % 2;
            num = num / 2;
        }
        push(q, arr);
    }

    display(q);
}
int main()
{
    queue *q = (queue *)malloc(sizeof(queue));
    int n;
    scanf("%d", &n);
    queueInit(q, n);

    binary(q, n);
}