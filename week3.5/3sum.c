#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int isDigit(char c){
    if(c>='0' && c<='9'){
        return 1;
    }
    else{
        return 0;
    }
}
void sortArray(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void findTriplets(int arr[], int n){
    sortArray(arr, n);
    printf("[");
    int flag=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++ ){
            for(int k=j+1; k<n; k++){
                if(i>0  && (arr[i] == arr[i-1] || arr[j] == arr[j-1] || arr[k] == arr[k-1])) continue;
                if((arr[i]+arr[j]+arr[k]==0) && flag==0){
                    printf("[%d %d %d]", arr[i], arr[j], arr[k]);
                    flag = 1;
                }
                else if((arr[i]+arr[j]+arr[k]==0) && flag==1){
                    printf(",[%d %d %d]", arr[i], arr[j], arr[k]);
            }
        }
    }
    }
        printf("]");
}

int main() {
    char string[105];
    scanf("%[^\n]", string);
    int *arr = (int *)malloc(105 * sizeof(int));
    // int arr[105];
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

    findTriplets(arr, count);
    return 0;
}

