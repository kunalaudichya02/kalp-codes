#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int *arr;
    int top;
    int size;
} stack;

void stackInit(stack* s, int size){
    s->top = -1;
    s->size = size;
    s->arr = (int*)malloc(size* sizeof(int));
}

void push(stack* s, int data){
    if(s->top >= s->size-1){
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = data;
}

int pop(stack *s){
    if(s->top == -1){
        printf("Stack underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

void pse(stack* s, int* arr){

    int n = s->size;
    int pse[n];

    for(int i=0; i<n; i++){
        while(s->top >=0 && s->arr[s->top]>arr[i]){
            pop(s);
        }
        if(s->top==-1){
            pse[i] = -1;
        }
        else{
            pse[i] = s->arr[s->top];
        }

        push(s, arr[i]);
    }

    for(int i=0; i<n; i++){
        printf("%d ", pse[i]);
    }
}

int main(){
    stack* s = (stack*)malloc(sizeof(stack));
    stackInit(s, 5);
    int arr[5];
    for(int i=0; i<5; i++){
        scanf("%d", &arr[i]);
    }

    pse(s, arr);
}