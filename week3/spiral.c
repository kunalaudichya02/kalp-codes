#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[100];
    scanf("%[^\n]", input);

    int array[100][100];
    int rows = 0, cols = 0, temp = 0;
    int i = 0, j = 0, k = 0; 
    int maxCols = 0;

    while (input[k] != '\0') {
        if (isdigit(input[k])) {
            temp = temp * 10 + (input[k] - '0'); 
        } else if (input[k] == ' ' || input[k] == ',' || input[k] == ']') {
            if (temp > 0 || input[k - 1] == '0') { 
                array[i][j++] = temp;
                temp = 0;
            }
        } else if (input[k] == '[') {
            if (j > 0) {
                rows++;
                if (j > maxCols) {
                    maxCols = j;
                }
                j = 0;    
                i++;
            }
        }
        k++;
    }

    if (j > 0) {
        rows++;
        if (j > maxCols) {
            maxCols = j;
        }
    }
    cols = maxCols;

    int top = 0;
    int left = 0;
    int right = cols - 1;
    int bottom = rows - 1;

    printf("[");

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            if (i == left && top == 0 && left == 0) {
                printf("%d", array[top][i]);
            } else {
                printf(" %d", array[top][i]);
            }
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            printf(" %d", array[i][right]);
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                printf(" %d", array[bottom][i]);
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                printf(" %d", array[i][left]);
            }
            left++;
        }
    }

    printf("]");
    return 0;
}