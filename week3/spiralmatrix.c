#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char string[100];
    scanf("%[^\n]", string);

    int matrix[10][10];
    int m = 0, n = 0, maxCols = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        if (isdigit(string[i]) || (string[i] == '-' && isdigit(string[i + 1]))) {
            int num = 0, sign = 1;
            if (string[i] == '-') {
                sign = -1;
                i++;
            }
            while (isdigit(string[i])) {
                num = num * 10 + (string[i] - '0');
                i++;
            }
            i--; // Adjust index after exiting the loop
            matrix[m][n++] = sign * num;
            if (n > maxCols) maxCols = n; // Track max columns
        } else if (string[i] == ' ' || string[i] == ',') {
            continue; // Skip separators
        } else if (string[i] == ']') {
            m++; // Move to the next row
            n = 0; // Reset column counter
        }
    }

    int top = 0, bottom = m - 1, left = 0, right = maxCols - 1;
    int result[m * n], index = 0;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) result[index++] = matrix[top][i];
        top++;
        for (int i = top; i <= bottom; i++) result[index++] = matrix[i][right];
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) result[index++] = matrix[bottom][i];
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) result[index++] = matrix[i][left];
            left++;
        }
    }

    printf("[");
    for (int i = 0; i < index; i++) {
        printf("%d", result[i]);
        if (i != index - 1) printf(" ");
    }
    printf("]\n");
    return 0;
}
