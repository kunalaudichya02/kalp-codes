#include<stdio.h>
#include<stdlib.h>

int checkPrime(int i){
    if(i==0) return 0;
    if(i==1) return 0;
    if(i==2) return 1;
    for(int j=2; j<i; j++){
        if(i%j == 0){
            return 0;
        }
    }
    return 1;
}
void shift(char *str, int c){
    // char c = n - '0';
    for(int i=0; str[i]!='\0'; i++){
        if(checkPrime(i) ){
            str[i] = str[i] + c;
        }
    }
}
int main(){
    printf("Enter an string: ");
    char str[100];
    scanf("%[^\n]%*c", str);
    int n;
    scanf("%d", &n);
    shift(str, n );
    printf("%s", str);
    return 0;
}