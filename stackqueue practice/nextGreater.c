#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int top;
    int size;
    int* arr;
} stack;

void stackInit(stack* s, int size){
    s->size = size;
    s->arr = (int *)malloc(size* sizeof(int));
    s->top = -1;
}

void push(stack* s, int data){
    if(s->top == s->size-1){
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = data;
}

int pop(stack* s){
    if(s->top == -1){
        printf("Stack underflow\n");
        return -1;
    }

    return s->arr[s->top--];
}


void nge(stack*s, int* arr){
    int n = s->size;
    int nge[n];
    for(int i=n-1; i>= 0; i--){
        while(s->top >=0 && s->arr[s->top] < arr[i]){
            pop(s);
        }
        if(s->top == -1){
            nge[i] = -1;
        }
        else{
            nge[i] = s->arr[s->top];
        }
        push(s, arr[i]);
    }


    for(int i=0; i<n; i++){
        printf("%d ", nge[i]);
    }
}
int main(){
    stack *s = (stack*)malloc(sizeof(stack));
    int size = 7;
    stackInit(s, size);
    int arr[size];
    // int data;
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    nge(s, arr);
}

