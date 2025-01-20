#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int m,n;
    scanf("%d %d", &m, &n);
    char names[n][50];
    int data[n][m];
    for(int i=0; i<m; i++){
        scanf("%s", names[i]);
        for(int j=0; j<n; j++){
                scanf("%d", &data[i][j]);
        }
    }

    int maxRevenue = 0;
    for(int i=0; i<m; i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            sum += data[i][j];
        }
        if(sum>maxRevenue){
            maxRevenue = sum;
        }
    }

    for(int i=0; i<m; i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            sum += data[i][j];
        }
        if(sum == maxRevenue){
            printf("%s\n", names[i]);
        }
    }


    
    return 0;
}
