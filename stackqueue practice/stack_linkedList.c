#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} node;

typedef struct stack{
    struct Node* top;
    int size;
} stack;

void stackInit(stack*s){
    s->size = 0;
    s->top = NULL;
}

node* createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

int isEmpty(stack * s){
    if(s->top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(stack* s){
    node* newNode = createNode(-1);
    if(newNode== NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void push(stack* s, int data){
    node* newNode = createNode(data);
    if(newNode == NULL){
        printf("stack overflow\n");
        return;
    }
    if(s->top == NULL){
        s->top = newNode;
        s->size++;
        return;
    }
    newNode->next = s->top;
    s->top = newNode;
    s->size++;

}

void pop(stack* s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return;
    }
    node* temp = s->top;
    s->top = s->top->next;
    temp->next = NULL;
    free(temp);
    s->size--;
}

int stackSize(stack *s){
    if(isEmpty(s)){
        return 0;
    }
    else{
        return s->size;
    }
}

int peek(stack* s){
    if(isEmpty(s)){
        return -1;
    }
    return s->top->data;
}

void display(stack* s){
    if(isEmpty(s)){
        printf("stack is empty\n");
        return;
    }
    else{
        node* temp = s->top;
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main(){
    stack * s = (stack*)malloc(sizeof(stack));
    stackInit(s);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    push(s, 8);
    push(s, 9);
    display(s);
    pop(s);
    pop(s);
    
    display(s);


}