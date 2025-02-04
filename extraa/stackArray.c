#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int *arr;
    int top;
    int size;
} stack;

void stackInit(stack *s, int size){
    s->size = size;
    s->top = -1;
    s->arr = (int *)malloc(size*sizeof(int));
    if(!s->arr){
        printf("memory allocation failed\n");
        return;
    }
}

int isEmpty(stack * s){
    if(s->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(stack* s){
    if(s->top == s->size -1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(stack* s, int data){
    if(isFull(s)){
        printf("Stack Overflow\n");
    }
    else{
        s->top++;
        s->arr[s->top] = data;
    }
}

int pop(stack*s){
    if(isEmpty(s)){
        printf("Stack underflow\n");

    }
    else{
        int pop = s->arr[s->top];
        s->top--;
        return pop;
    }
}

int stackSize(stack *s){
    if(isEmpty(s)){
        printf("stack is empty\n");
        return 0;
    }
    else{
        return s->top+1;
    }
}

void display(stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }
    else{
        for(int i=0; i<=s->top; i++){
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}
int main(){
    stack* s = (stack*)malloc(sizeof(stack));
    int size;
    scanf("%d", &size);
    stackInit(s, size);
    
    push(s, 4);
    push(s, 44);
    push(s, 43);
    push(s, 45);
    push(s, 3);
    printf("size: %d\n", stackSize(s));
    display(s);
    pop(s);
    pop(s);
    pop(s);
    display(s);
}