#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    char * str;
    int top;
    int size;
} stack;

void stackInit(stack*s){
    s->top = -1;
    s->size = 100;
    s->str = (char*)malloc(100* sizeof(char));
}

void push(stack*s , char c){
    if(s->top >= s->size-1 ){
        printf("stack overflow\n");
        return;
    }
    s->top++;
    s->str[s->top] = c;
}

char pop(stack *s){
    if(s->top == -1){
        printf("Stack underflow\n");
        return '\0';
    }
    return s->str[s->top--];
}

void reverseString(stack* s, char* str){
    int i=0;
    while(str[i] != '\0'){
        push(s, str[i]);
        i++;
    }
    i=0;
    while(s->top != -1){
        char popped = pop(s);
        str[i++] = popped;
    }
    str[i] = '\0';
}
int main(){
    stack *s = (stack*)malloc(sizeof(stack));
    stackInit(s);
    char str[100];
    scanf("%s", str);
    reverseString(s, str);
    printf("%s", str);
    return 0;
}