#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char input[500];
    fgets(input, sizeof(input), stdin); // Read the input line

    // Variables to hold the matrix size
    int m = 0, n = 0;
    int matrix[10][10]; // Maximum dimensions based on the constraints (1 <= m, n <= 10)

    // Parse the input
    int row = 0, col = 0, num = 0;
    int inside_number = 0; // To track if we're parsing a number

    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        if (isdigit(ch) || ch == '-') { // A digit or a negative sign starts a number
            if (!inside_number) {
                inside_number = 1;
                num = (ch == '-') ? 0 : ch - '0'; // Handle negative numbers
                if (ch == '-') num = -num;
            } else {
                num = num * 10 + (ch - '0'); // Accumulate the number
            }
        } else if (inside_number) { // End of the current number
            matrix[row][col++] = num;
            inside_number = 0;

            // Reset num for the next number
            num = 0;

            // If we encounter a comma, check for new row
            if (ch == ',' && input[i + 1] == '[') {
                if (n == 0) n = col; // Set the column count for the first row
                row++;
                col = 0;
            }
        }
    }

    if (inside_number) { // Add the last number if parsing ended
        matrix[row][col++] = num;
    }
    m = row + 1; // Total rows
    if (n == 0) n = col; // For single-row input

    // Now m and n are determined, and matrix is populated
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    int result[m * n], idx = 0;

    // Spiral traversal
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) result[idx++] = matrix[top][i];
        top++;
        for (int i = top; i <= bottom; i++) result[idx++] = matrix[i][right];
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) result[idx++] = matrix[bottom][i];
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) result[idx++] = matrix[i][left];
            left++;
        }
    }

    // Print the result
    printf("[");
    for (int i = 0; i < idx; i++) {
        printf("%d", result[i]);
        if (i != idx - 1) printf(" ");
    }
    printf("]\n");

    return 0;
}