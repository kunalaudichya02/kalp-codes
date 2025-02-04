#include<stdio.h>
#include<stdlib.h>

typedef struct Queue {
    int * arr;
    int front;
    int rear; 
    int size;
} queue;

void queueInit(queue * q, int size){
    q->size = size;
    q->arr = (int*)malloc(size * sizeof(int));
    q->front = -1;
    q->rear = -1;
}

int isEmpty(queue *q){
    if(q->rear < 0){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(queue * q){
    if(q->rear == q->size -1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(queue * q, int data){
    if(isFull(q)){
        printf("Queue overflow\n");
        return ;
    }
    else{
        if(q->front == -1){   
          q->front++;
        }
        q->rear++;
        q->arr[q->rear] = data;
    }
}

int dequeue(queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        int removed = q->arr[q->front];
        q->front++;
        return removed;
    }
}

int queueSize(queue * q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        return q->rear - q->front + 1;
    }
}

int peek(queue * q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        return q->arr[q->front];
    }
}

void display(queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return ;
    }
    else{
        for(int i= q->front; i<= q->rear; i++){
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}
int main(){
    queue *q = (queue*)malloc(sizeof(queue));
    int size = 5;
    queueInit(q, size);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    enqueue(q, 8);
    enqueue(q, 0);
    display(q);
    printf("%d\n", queueSize(q));
    dequeue(q);
    dequeue(q);
    dequeue(q);
    // enqueue(q, 7);
    display(q);
    printf("%d", queueSize(q));
}