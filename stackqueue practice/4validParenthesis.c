#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack{
    char str[50];
    int top;
} stack;

void stackInit(stack *s){
    s->top = -1;
}

void push(stack *s, char c){
    s->top++;
    s->str[s->top] = c;
}

char pop(stack* s){
    if(s->top == -1) return 0;
    return s->str[s->top--];
}

int findValidity(stack* s, char* str){
    for(int i=0; i<strlen(str); i++){
        char c = str[i];
        if(c == '(' || c== '[' || c=='{'){
            push(s, c);
        }
        if(c == ')'){
            if(s->str[s->top] == '('){
                pop(s);
            }
            else{
                push(s, c);
            }
        }
        if(c == '}'){
            if(s->str[s->top] == '{'){
                pop(s);
            }
            else{
                push(s, c);
            }
        }
        if(c == ']'){
            if(s->str[s->top] == '['){
                pop(s);
            }
            else{
                push(s, c);
            }
        }
    }

    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    stack *s = (stack*)malloc(sizeof(stack));
    stackInit(s);

    char str[50];
    scanf("%s", str);
    
    if(findValidity(s, str)){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
}