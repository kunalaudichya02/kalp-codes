#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int isDigit(char c){
    if(c>='0' && c<='9'){
        return 1;
    }
    else{
        return 0;
    }
}

int nextGen(int **a, int row, int col){
    int b[row][col];
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            
                int sum = 0;
                if (i-1 >= 0 && j-1 >= 0) sum += a[i-1][j-1];
                if (i-1 >= 0) sum += a[i-1][j];
                if (i-1 >= 0 && j+1 < col) sum += a[i-1][j+1];
                if (j-1 >= 0) sum += a[i][j-1];
                if (j+1 < col) sum += a[i][j+1];
                if (i+1 < row && j-1 >= 0) sum += a[i+1][j-1];
                if (i+1 < row) sum += a[i+1][j];
                if (i+1 < row && j+1 < col) sum += a[i+1][j+1];
            
             if(a[i][j]==0){
                if(sum==3){
                   b[i][j] = 1;
                  }
                 else{
                  b[i][j] = 0;
                 }
             }
             else if(a[i][j]==1){
                    if(sum <=1){
                        b[i][j] = 0;
                    }
                    else if(sum >= 4){
                        b[i][j] = 0;
                    }
                    else{
                       b[i][j]= 1;
                        }
             }
        }
    }
    
    printf("[");
    for(int i=0; i<row; i++){
        int flag=0;
        printf("[");
        for(int j=0; j<col; j++){
            if(flag==0){
                printf("%d", b[i][j]);
                flag=1;
            }
            else{
                printf(" %d", b[i][j]);
            }
        }
        if(i!=row-1){ printf("],"); }
        else printf("]");
        
    }
    printf("]");
    return 0;
}
int main(){
    char input[1000];
    scanf("%[^\n]", input);
    int n=0, m=0;  

    int maxRow = 25, maxCol = 25;
    int **arr = (int **)malloc(maxRow * sizeof(int*));
    for(int i=0; i<maxRow; i++){
      arr[i] = (int *)malloc(maxCol * sizeof(int));
    } 
    for(int i=0; input[i] != '\0'; i++){
      if(input[i]=='[' || input[i]==']' || input[i]==' '){
            i++;
      }
      if(isDigit(input[i])){
          arr[n][m++] = (input[i] - '0');
      }
      if(input[i]==','){
          n++;
          m=0;
      }
    }
    int row = n+1;
    int col = m;
    nextGen(arr, row, col);

    for(int i = 0; i < row; i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}
    
