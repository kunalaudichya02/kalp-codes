#include<stdio.h>


void merge(int * arr, int low, int mid, int high){
    int temp[high-low+1];
    int left = low;
    int right = mid+1;
    int i=0;
    while(left<= mid && right<= high ){
        if(arr[left] <= arr[right]){
            temp[i++] = arr[left];
            left++;
        }
        else{
            temp[i++] = arr[right];
            right++;
        }
    }

    while(left<= mid){
         temp[i++] = arr[left];
         left++;
    }
    while(right <= high){
          temp[i++] = arr[right];
          right++;  
    }

    for(int j=0; j<i; j++){
        arr[low+j] = temp[j];
    }
}
void mergeSort(int * arr, int low, int high){

    if(low== high){
        return;
    }
    int mid = (low + (high - low)/2);
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}
void display(int * arr, int size){
    for(int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[]={2, 4, 1, 56, 23, 0, 7};
    mergeSort(arr, 0, 6);
    display(arr, 7);
}