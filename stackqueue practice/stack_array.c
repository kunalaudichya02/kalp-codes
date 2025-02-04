#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int *arr;
    int top;
    int size;
} stack;

void stackInit(stack *s, int size){
    s->size = size;
    s->arr = (int *)malloc(size * sizeof(int));
    s->top = -1;
}

int isEmpty(stack* s){
    if(s->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(stack* s){
    if(s->top < s->size-1){
        return 0;
    }
    else{
        return 1;
    }
}
void push(stack* s, int data){
    if(isFull(s)){
        printf("Stack Overflow\n");
        return;
    }
    else{
        s->arr[++s->top] = data;
    }
}

int pop(stack* s){
    if(isEmpty(s)){
        printf("Stack underflow\n");
    }
    else{
        int popped = s->arr[s->top];
        s->top--;
        return popped;
    }
}

int stackSize(stack * s){
    return s->top+1;
}

int peek(stack* s){
    if(isEmpty(s)){
        printf("Stack underflow\n");
    }
    else{
        int peek = s->arr[s->top];
        return peek;
    }
}

void display(stack * s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return;
    }
    else{
        for(int i=0; i<= s->top ; i++){
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

int main(){
    stack* s = (stack*)malloc(sizeof(stack));
    int size = 5;
    // scanf("%d", &size);
    stackInit(s, size);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 6);
    push(s, 6);
    push(s, 6);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    // pop(s);
    display(s);

    printf("%d\n", peek(s));
    printf("%d", stackSize(s));

}