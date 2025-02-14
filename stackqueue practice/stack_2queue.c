#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int * arr;
    int size;
    int front;
    int rear;
} queue;

typedef struct stack{
    queue* q1;
    queue* q2;
    int size;
} stack;


void queueInit(queue* q, int size){
    q->size = size;
    q->arr = (int*)malloc(size* sizeof(int));
    q->front = -1;
    q->rear = -1;
}

void stackInit(stack *s, int size){
    s->size = size;
    s->q1 = (queue*)malloc(sizeof(queue));
    s->q2 = (queue*)malloc(sizeof(queue));
    queueInit(s->q1, size);
    queueInit(s->q2, size);
}

void enqueue(queue *q, int data){
    if(q->rear == q->size -1){
        printf("Queue full\n");
        return;
    }
    if(q->front == -1){
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = data;
}

int dequeue(queue* q){
    if(q->front == -1 || q->front > q->rear){
        printf("Queue empty\n");
    }
    else{
        return q->arr[q->front++];
    }

}


int isEmpty(queue*q){
    if(q->front == -1 || q->front > q->rear){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(queue*q){
    if(q->rear == q->size -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(stack*s, int data){
    enqueue(s->q2, data);

    while(!isEmpty(s->q1)){
        int popp = dequeue(s->q1);
        enqueue(s->q2, popp);
    }

    queue* temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}


int pop(stack*s){
    if(isEmpty(s->q1)){
        return -1;
    }
    return dequeue(s->q1);
}

void display(stack *s) {
    if (isEmpty(s->q1)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = s->q1->front; i <= s->q1->rear; i++) {
        printf("%d ", s->q1->arr[i]);
    }
    printf("\n");
}
int main(){
    stack* s = (stack*)malloc(sizeof(stack));
    stackInit(s, 5);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    display(s);
    pop(s);
    pop(s);
    display(s);

    return 0;
}