#include <stdio.h>

int main()
{
    printf("enter dimensions \n");
    int n;
    scanf("%d", &n);

    int image[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            image[i][j] = 0;
        }
    }

    printf("enter operations \n");
    int m;
    int row;
    int col;
    scanf("%d", &m);

    for (int i = m; i > 0; i--)
    {
        int x;
        scanf("%d", &x);
        if (x == 1)
        {
            scanf("%d", &row);
            scanf("%d", &col);
        };

        switch (x)
        {
        case 1:
        {
            if (image[row - 1][col - 1] == 0)
            {
                image[row - 1][col - 1] = 1;
            }
            else
            {
                image[row - 1][col - 1] = 0;
            }
        }
        break;

        case 2:
        {
            for (int i = 0; i < n; i++)
            {
                    int start = 0;
                    int end = n - 1;
                    while (start < end)
                    {
                        int temp = image[start][i];
                        image[start][i] = image[end][i];
                        image[end][i] = temp;

                        start++;
                        end--;
                    
                }
            }
        }
        break;

        case 3:
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    int temp = image[i][j];
                    image[i][j] = image[j][i];
                    image[j][i] = temp;
                }
            }

            for (int i = 0; i < n; i++)
            {
                    int start = 0;
                    int end = n - 1;
                    while (start < end)
                    {
                        int temp = image[start][i];
                        image[start][i] = image[end][i];
                        image[end][i] = temp;

                        start++;
                        end--;

                }
            }
        }
        break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}