#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int *arr;
    int size;
    int top;
} stack;

typedef struct queue{
    stack* s1;
    stack* s2;
} queue;

void stackInit(stack*s, int size){
    s->arr = (int*)malloc(size* sizeof(int));
    s->size = size;
    s->top = -1;
}

void queueInit(queue*q, int size){
    q->s1 = (stack*)malloc(sizeof(stack));
    q->s2 = (stack*)malloc(sizeof(stack));
    stackInit(q->s1, size);
    stackInit(q->s2, size);
}

int isEmpty(stack* s){
    if(s->top == -1){
        return 1;
    }
    else return 0;

}

int isFull(stack *s){
    if(s->top == s->size-1){
        return 1;
    }
    else return 0;
}
void push(stack*s, int data){
    if(isFull(s)){
        printf("stack overflow\n");
        return;
    }
    else{
        s->top++;
        s->arr[s->top] = data;
    }
}

int pop(stack *s){
    if(isEmpty(s)){
        printf("empty\n");
        return -1;
    }
    else{
        int popp = s->arr[s->top];
        s->top--;
        return popp;
    }
}

void enqueue(queue *q, int data){
    push(q->s1, data);
}

int dequeue(queue* q){
    if(isEmpty(q->s2)){
        while(!isEmpty(q->s1)){
            int temp = pop(q->s1);
            push(q->s2, temp);
        }
    }
    if(isEmpty(q->s2)){
        printf("queue is empty\n");
        return -1;
    }

    return pop(q->s2);
}

void display(queue* q){
    if(isEmpty(q->s1) && isEmpty(q->s2)){
        printf("Queue is empty\n");
        return;
    }
    for(int i=0; i<=q->s2->top; i++){
        printf("%d ", q->s2->arr[i]);
    }
    for(int i= q->s1->top; i>=0; i--){
        printf("%d ", q->s1->arr[i]);
    }
    printf("\n");
}

int main(){
    queue *q = (queue*)malloc(sizeof(queue));
    queueInit(q, 10);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    display(q);
    dequeue(q);
    dequeue(q);
    display(q);
}