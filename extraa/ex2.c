#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void stringCopy(char *dest, const char *src) {
    while (*src != '\0') {  
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; 
}
void appendString(char *s, char **stack, int *top){
    char *str = (char *)malloc(1000000* sizeof(char));
    char *temp = (char *)malloc(1000000* sizeof(char));
    stack[*top] = (char *)malloc(1000000 * sizeof(char));
    
    scanf(" %[^\n]", str);
    int i=0, j=0;
    while(s[i] != '\0'){
        i++;
    }
    
    while(str[j] != 0){
        s[i++] = str[j++];
    }
    
    s[i]= '\0';
    stringCopy(temp, s);
    
    stringCopy(stack[*top], temp);
    (*top)++; 
    printf("string after append: %s\n top: %d\n", s, *top);
}

void deleteLastK(char *s, char **stack, int *top){
    stack[*top] = (char *)malloc(1000000 * sizeof(char));
    char *temp = (char *)malloc(1000000* sizeof(char));
    char *ptr = s;
    int k;
    scanf("%d", &k);
    int size =0;
    while(*ptr != '\0'){
        size++;
        ptr++;
    }
    int i= size -k;
    s[i] = '\0';
    stringCopy(temp, s);
    stringCopy(stack[*top], temp);

    (*top)++; 
    printf("string after delete: %s\n top: %d\n", s, *top);
}

void printKth(char *s, char **stack, int *top){
    stack[*top] = (char *)malloc(1000000 * sizeof(char));
    char *temp = (char *)malloc(1000000* sizeof(char));
    int k;
    scanf("%d", &k);
    printf("%c\n", s[k-1]);
    stringCopy(temp, s);
    stringCopy(stack[*top], temp);
    
    (*top)++; 
    printf("string after print: %s\n top: %d\n", s, *top);
}

void undo(char *s, char **stack, int *top){
    (*top)--;
    stringCopy(s, stack[*top]);
    printf("string after undo: %s\n top: %d\n", s, *top);
}

int main() {
    int op;
    scanf("%d", &op);
    char *s = (char *)malloc(1000000* sizeof(char));
    s[0] = '\0';
    
    char **stack = (char **)malloc(op * sizeof(char *));
    stack[0] = (char *)malloc(1000000* sizeof(char));
    stringCopy(stack[0], s);
    int top =1;
    while(op>0){
        int n;
        scanf("%d", &n);
        
        switch (n){
            case  1:{
                appendString(s, stack, &top);
                printf("\n");
            }
            break;
                
            case  2:{
                deleteLastK(s, stack, &top);
                 printf("\n");
            }
            break;
                
            case  3:{
                printKth(s, stack, &top);
                 printf("\n");
            }
            break;
                
            case  4:{
                undo(s, stack, &top);
                 printf("\n");
            }
            break;          
        }
        op--;
    }
    return 0;
}
