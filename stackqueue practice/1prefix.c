#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack{
    char **str;
    int top;
} stack;

void stackInit(stack * s){
    s->top = -1;
    s->str = (char**)malloc(100*sizeof(char*));
}

void push(stack *s, char *str){
    s->top++;
    s->str[s->top] = (char*)malloc(strlen(str) + 1);
    strcpy(s->str[s->top], str);
}
void pushCh(stack *s, char c){
    s->top++;
    s->str[s->top] = (char*)malloc(2);
    s->str[s->top][0] = c;
    s->str[s->top][1] = '\0'; 

}

char* pop(stack *s){
    if(s->top == -1) return NULL;
    return s->str[s->top--];
}

char* toinfix(stack*s, char* str){
    int len = strlen(str);
    for(int i=len-1; i>=0; i--){
        char c= str[i];
        if((c >= 'a' && c <= 'z') ||( c >= 'A' && c <= 'Z')){
            pushCh(s, c);
        }
        if((c == '+' || c== '-' || c=='*' || c=='%' || c=='/' || c=='^') && s->top>=1){
            char* str1 = pop(s);
            char* str2 = pop(s);
            
            char * new = (char*)malloc(strlen(str1) + strlen(str2) + 5);

            sprintf(new, "(%s%c%s)", str1, c, str2);
            push(s, new);
            
            free(str1);
            free(str2);
        }
    }

    return pop(s);
}
int main(){
    char *str = (char*)malloc(100 * sizeof(char));
    scanf("%s", str);

    stack *s = (stack*)malloc(sizeof(stack));
    stackInit(s);

    char *result = toinfix(s, str);
    printf("%s\n", result);

    free(result);
    for (int i = 0; i <= s->top; i++) {
        free(s->str[i]);
    }
    free(s->str);
    free(s);
    free(str);

    return 0;
}