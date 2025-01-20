#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //a & b
  
    int maxAnd = 0;
  for(int i =1; i<n; i++){
    for(int j=i+1; j<=n; j++){
        int sum = i & j;
        if(sum>maxAnd && sum < k){
           maxAnd = sum;
        }
    }
  }
  printf("%d\n", maxAnd);

  //a | b
  int maxOr =0;
   for(int i =1; i<n; i++){
    for(int j=i+1; j<=n; j++){
        int sum = i | j;
        if(sum> maxOr && sum < k){
           maxOr = sum;
        }
    }
  }
  printf("%d\n", maxOr);


  //a ^ b
  int maxXor = 0;
   for(int i =1; i<n; i++){
    for(int j=i+1; j<=n; j++){
        int sum = i ^ j;
        if(sum>maxXor && sum < k){
           maxXor = sum;
        }
    }
  }
  printf("%d\n", maxXor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
