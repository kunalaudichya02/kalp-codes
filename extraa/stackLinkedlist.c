#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} node;

typedef struct Stack{
    struct Node* top;
    int size;
} stack;

void stackInit(stack *s){
    s->top = NULL;
    s->size = 0;
}

int isEmpty(stack *s){
    if(s->top == NULL){
      return 1;
    }
    else return 0;
}

int isFull(stack *s){
    node * n = (node*)malloc(sizeof(node));
    if(n== NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void push(stack *s, int data){
    if(isFull(s)){
        printf("stack overflow");
    }
    else{
        node* new =(node*)malloc(sizeof(node));
        new->data = data;
        new->next = s->top;
        s->top = new;
        s->size++;
    }
}

int pop(stack *s){
    if(isEmpty(s)){
        printf("stack is empty");
    }
    else{
        node*n =(node*)malloc(sizeof(n));
        int pop = s->top->data;
        n = s->top;
        s->top = s->top->next;
        free(n);
        s->size--;
        return pop;
    }
}

int peek(stack *s){
    if(isEmpty(s)){
        printf("stack is empty");
    }
    else{
        int peek = s->top->data;
        return peek;
    }
}

int stackSize(stack*s){
    return s->size;
}

void display(stack *s){
    if(isEmpty(s)){
        printf("stack is empty\n");
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
    stack *s = (stack*)malloc(sizeof(stack));
    stackInit(s);
    display(s);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 55);
    push(s, 23);
    printf("%d\n", stackSize(s));
    printf("%d\n", peek(s));
    display(s);
    pop(s);
    pop(s);
    pop(s);
    printf("%d\n", stackSize(s));
    printf("%d\n", peek(s));
    display(s);
}