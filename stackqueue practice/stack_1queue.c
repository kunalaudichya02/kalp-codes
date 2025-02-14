#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int* arr;
    int front;
    int rear;
    int size;
    int maxSize;
} queue;

void queueInit(queue * q, int n){
    q->maxSize = n;
    q->arr = (int*)malloc(n* sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}


int isEmpty(queue *q){
    if(q->size==0 || q->front==-1){
        return 1;
    }
    else return 0;
}

int isFull(queue *q){
    if(q->rear == q->maxSize-1){
        return 1;
    }
    else return 0;
}
void enqueue(queue* q, int data){
    if(isFull(q)){
        printf("QUeue is full\n");
        return;
    }
    else{
        if(q->front == -1){
            q->front++;
        }
        q->rear++;
        q->arr[q->rear] = data;
        q->size++;
    }
}

int dequeue(queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        int data = q->arr[q->front];;
        q->front++;
        q->size--;
        if(q->size == 0){
            q->front = -1;
            q->rear = -1;
        }
        return data;

    }
}


void push(queue *q, int data){
    if(isFull(q)){
        return;
    }
    else{
        enqueue(q, data);
        for(int i =0 ; i< q->size-1; i++){
            int popped = dequeue(q);
            enqueue(q, popped);
        }
    }
}

int pop(queue *q){
    if(isEmpty(q)){
        return -1;
    }
    else{
        return dequeue(q);
    }
}

void display(queue *q) {
    if (isEmpty(q)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main(){
    queue *q = (queue*)malloc(sizeof(queue));
    queueInit(q, 100);
    push(q, 5);
    push(q, 6);
    push(q, 7);
    push(q, 8);
    push(q, 9);
    display(q);
    pop(q);
    pop(q);
    pop(q);
    display(q);
}