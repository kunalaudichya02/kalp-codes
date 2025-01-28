#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void sortMeals(int hotel[], int n){
    int meals = 0;
    int juices = 0;
    int chats = 0;
    for(int i =0; i<n; i++){
            if(hotel[i]==0) meals++;
            else if(hotel[i]==1) juices++;
            else chats++;
    }

    int *ptr = hotel;
    for(int i=0; i<meals; i++){
        *(ptr + i) = 0;
    }
    for(int i=meals; i<(meals + juices); i++){
        *(ptr + i) = 1;
    }
    for(int i=(meals + juices); i<n; i++){
        *(ptr + i) = 2;
    }

    for(int i=0; i<n; i++){
        printf("%d\n", hotel[i]);
    }
    return 0;

         
}
int main() {
    int n;
    scanf("%d", &n);
    int hotel[n];
    for(int i=0; i<n; i++){
        scanf("%d", &hotel[i]);
    }
    sortMeals(hotel, n);
    return 0;
}


// void function(int hotel[], int n){
//     int meals = 0;
//     int juices = 0;
//     int chats = 0;

//     for(int i =0; i<n; i++){
//         if(hotel[i]==0) meals++;
//         else if(hotel[i]==1) juices++;
//         else chats++;
//     }

//     while(meals != 0){
//         printf("0\n");
//         meals--;
//     }
//     while(juices != 0){
//         printf("1\n");
//         juices--;
//     }
//     while(chats != 0){
//         printf("2\n");
//         chats--;
//     }
// }
