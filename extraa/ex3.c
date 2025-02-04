#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void append(char **stack, int top)
{
    char *input = (char *)malloc(1001 * sizeof(char));
    scanf("%[^\n]s", input);
    getchar();
    int size_of_prev_string = strlen(stack[top - 1]);
    int size = strlen(input);
    stack[top] = (char *)malloc((size_of_prev_string + size + 1) * sizeof(char));
    for (int i = 0; i < size_of_prev_string; i++)
        stack[top][i] = stack[top - 1][i];
    for (int i = 0; i < size; i++)
        stack[top][size_of_prev_string + i] = input[i];
    stack[top][size_of_prev_string + size] = '\0';
    free(input);
    return;
}

void delete_k_last_elements(char **stack, int top, int k)
{
    int size_of_prev_string = strlen(stack[top - 1]);
    stack[top] = (char *)malloc((size_of_prev_string - k + 1) * sizeof(char));
    int i = 0;
    for (i = 0; i < (size_of_prev_string - k); i++)
    {
        stack[top][i] = stack[top - 1][i];
    }
    stack[top][i] = '\0';
    return;
}

void print_k_element_from_start(char **stack, int top, int k)
{
    printf("%c\n", stack[top][k - 1]);
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    char **stack = (char **)malloc(n * sizeof(char *));
    stack[0] = (char *)malloc(1 * sizeof(char));
    stack[0][0] = '\0';
    int top = 0;

    while (n--)
    {
        int oper;
        scanf("%d", &oper);
        if (oper == 1)
        {
            getchar();
            append(stack, ++top);
        }
        else if (oper == 2)
        {
            int k;
            scanf("%d", &k);
            delete_k_last_elements(stack, ++top, k);
        }
        else if (oper == 3)
        {
            int k;
            scanf("%d", &k);
            print_k_element_from_start(stack, top, k);
        }
        else if (oper == 4)
        {
            free(stack[top]);
            top--;
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}