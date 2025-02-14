#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}node;

typedef struct queue{
    node* front;
    node* rear;
} queue;

node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void queueInit(queue *q){
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(queue *q, int data){
    node* newNode = createNode(data);
    if(newNode == NULL){
        printf("Queue overflow\n");
        return;
    }
    if(q->front == NULL){
        q->front = newNode;
        q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;

}

void dequeue(queue *q){
    if(q->front == NULL){
        printf("Queue is empty\n");
        return;
    }

    node* temp = q->front;
    q->front = q->front->next;
    temp->next = NULL;
    free(temp);
}

void display(queue *q){
   if(q->front == NULL){
        printf("Queue is empty\n");
        return;
    }

    node* temp = q->front;
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    queue * q = (queue *)malloc(sizeof(queue));
    queueInit(q);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    display(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    display(q);
}


