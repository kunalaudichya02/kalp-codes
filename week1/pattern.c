#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.

    for(int i=0; i<(2*n-1); i++){
        for(int j=0; j<(2*n-1); j++){
            //distance from each edge
            int top = i;
            int left = j;
            int right = 2*n-2 - j;
            int bottom = 2*n-2 - i;

            int min = 4*n - 4;

            if(top<min) min =top;
            if(left<min) min =left;
            if(right<min) min =right;
            if(bottom<min) min =bottom;
            printf("%d ", n-min);
            
        }

        printf("\n");
    }

    return 0;
}

  // int min = 4 * n - 4;
            // if(((i+j)- (i + 0))<min && ((i+j)- (i + 0)) > 0) min = ((i+j)- (i+0));
            // if(((i+j)- (i + (2*n-2)))<min && ((i+j)- (i + (2*n-2)))> 0) min = ((i+j)- (i + (2*n-2)));
            // if(((i+j)- (0 + j))<min && ((i+j)- (0 + j))> 0) min = ((i+j)- (0 + j));
            // if(((i+j)- ((2*n-0) + j ))<min && ((i+j)- ((2*n-0) + j ))) min = ((i+j)- ((2*n-0) + j ));