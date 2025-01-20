#include<stdio.h>

int main(){
    char string[100];
    printf("Enter a string \n");
    scanf("%[^\n]%*c", string);
    printf("Enter a shift value \n");
    int n;
    scanf("%d", &n);
    

    for(int i=0; string[i] != '\0'; i++){

        if( (i%3 == 0) && string[i] != ' ' && string[i] >= 'a' && string[i] <= 'z'){
                string[i] = (string[i] - 'a' + n)%26 + 'a';
        }
    }

    printf("%s", string);
    return 0;
}