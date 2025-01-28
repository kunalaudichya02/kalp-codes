#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int isDigit(char a){
    if(a>='0' && a<='9'){
    return 1;
    }
    else{
    return 0;
    }
}

int findSubarray(int arr[], int n){
    int maxSum = arr[0];
    for(int i=0; i<n; i++){
    int count = 0;
        for(int j=i; j<n; j++){
            count += arr[j];
            if(count > maxSum){
                maxSum = count;
            }
        }
    }
    printf("%d", maxSum);
    return 0;
}

int main() {
    char string[500];
    scanf("%[^\n]", string);
    int *arr = (int *)malloc(300 * sizeof(int));
    int count =0;
    for (int i = 0; string[i] != '\0'; i++) {
        while(string[i] == ' ' || string[i] == '['|| string[i] == ']') {
            i++;
            }
        if (isDigit(string[i]) || (string[i] == '-' && isDigit(string[i + 1]))) {
            int num = 0, sign = 1;
            if (string[i] == '-') {
                sign = -1;
                i++;
            }
            while (isDigit(string[i])) {
                num = num * 10 + (string[i] - '0');
                i++;
            }
            arr[count++] = sign * num;
    }     
    }
    findSubarray(arr, count);
    return 0;
}
