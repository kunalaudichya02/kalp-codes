#include<stdio.h>

void bubbleSort(int *arr, int size){
    for(int i=0; i<size; i++){
        int swapped = 0;
        for(int j=0 ; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        // if(swapped==0) break;
    }
}

void display(int * arr, int size){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[]={2, 4, 1, 56, 23, 0, 7};
    bubbleSort(arr, 7);
    display(arr, 7);
}