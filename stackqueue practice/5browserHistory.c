#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack{
    char** str;
    int top;
    int size;
} stack;


void stackInit(stack*s){
    s->str = (char**)malloc(100 * sizeof(char*));
    s->size = 100;
    s->top = -1;
}

void push(stack*s , char* str){
    if(s->top >= s->size -1 ){
        printf("Stack overflow\n");
        return;
    }
    s->top++;
    s->str[s->top] = (char*)malloc(strlen(str) + 1);
    strcpy(s->str[s->top], str);
}

void pop(stack *s){
    if(s->top == -1){
        printf("Stack underflow\n");
        return ;
    }
    free(s->str[s->top]);
    s->top--;
}

char * peek(stack *s){
     if(s->top == -1){
        printf("Stack underflow\n");
        return NULL ;
    }
    return s->str[s->top];
}

void display(stack *s){
    for(int i=s->top; i>=0; i--){
        printf("%s\n", s->str[i]);
    }
}

void update(stack*s){
    printf("Enter the list which you want to update: \n");
    for(int i=s->top, j=1 ; i>=0, j<=s->top + 1; i--, j++){
        printf("%d %s\n", j, s->str[i]);
    }
    int x;
    scanf("%d", &x);

    printf("\nEnter new URL: ");
    char str[100];
    scanf("%s", str);

    strcpy(s->str[s->top-x + 1], str);
}

void clearHistory(stack *s){

    while(s->top != -1){
        pop(s);
    }
}

int main(){
   stack s;
    stackInit(&s);

    push(&s, "https://google.com");
    push(&s, "https://github.com");
    push(&s, "https://stackoverflow.com");

    printf("\nCurrent History:\n");
    display(&s);

    printf("\nPeeking: %s\n", peek(&s));

    update(&s);

    printf("\nUpdated History:\n");
    display(&s);

    clearHistory(&s);
    printf("\nHistory cleared\n");

    free(s.str); // ✅ Free array of pointers
    return 0;
}
