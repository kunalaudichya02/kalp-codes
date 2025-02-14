#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int *arr;
    int size;
    int top;
} stack;

void stackInit(stack* s){
    s->arr = (int*)malloc(7 * sizeof(int));
    s->size = 7;
    s->top = -1;
}

void push(stack* s, int data){
    if(s->top == s->size -1){
        printf("stack overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = data;

}

int pop(stack *s){
    if(s->top == -1){
        printf("empty\n");
        return -1;
    }
    return s->arr[s->top--];
}

void pge(stack *s, int* arr){
    int n = s->size;
    int pse[n];
    for(int i=0; i<n; i++){
        int count = 1;
        while(s->top >=0 && arr[s->arr[s->top]]<arr[i]){
            count += pse[s->arr[s->top]];
            pop(s);
            // count++;
        }

        if(s->top == -1){
            pse[i] = 1;
        }
        else{
            pse[i] = count;
        }

        push(s, i);

    }

    for(int i=0; i<n; i++){
        printf("%d ", pse[i]);
    }
}

int main(){
    stack *s = (stack*)malloc(sizeof(stack));
    stackInit(s);
    int n = s->size;
    int arr[n];
    for(int i =0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    pge(s, arr);
}

