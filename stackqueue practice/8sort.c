#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int *arr;
    int top;
    int size; 
} stack;

void stackInit(stack* s){
    s->size = 5;
    s->arr = (int*)malloc(5  * sizeof(int));
    s->top = -1;
}

void push(stack* s, int data){
    if(s->top == s->size-1){
        printf("Stack overflow\n");
        return;
    }
    s->arr[++s->top] = data;
}

int pop(stack* s){
    if(s->top == -1){
        printf("Stack empty\n");
        return -1;
    }
    return s->arr[s->top--];
}

void sort(stack*s, stack* st){
    while(s->top >=0){
        int n = pop(s);
        // if(st->top == -1 || (n >= st->arr[st->top])){
        //     push(st, n);
        // }
        while(st->top != -1 && n > st->arr[st->top]){
            int x = pop(st);
            push(s, x);
        }
        push(st, n);
    }

    // while(st->top != -1){
    //     push(s, pop(st));
    // }
}

void display(stack* s){
      if(s->top == -1){
        printf("Stack empty\n");
        return ;
    }
    for(int i=s->top ; i>= 0; i--){
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main(){
    stack *s = (stack*)malloc(sizeof(stack));
    stack *st = (stack*)malloc(sizeof(stack));
    stackInit(s);
    stackInit(st);

    int data;
    while(scanf("%d", &data)){
        push(s, data);
        char c= getchar();
        if(c== '\n') break;
    }

    sort(s, st);
    display(st);

}