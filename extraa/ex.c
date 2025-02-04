int *waiter(int number_count, int *number, int q, int *result_count)
{
    int *answer = (int *)malloc(number_count * sizeof(int));
    int prime[q];
    int count = 0, num = 2;
    while (count < q)
    {
        if (isPrime(num))
            prime[count++] = num;
        num++;
    }
    int max = number_count;

    stack *a = (stack *)malloc(sizeof(stack));
    stack *b = (stack *)malloc(sizeof(stack));
    a->arr = (int *)malloc(max * sizeof(int));
    b->arr = (int *)malloc(max * sizeof(int));
    a->top = -1;
    b->top = -1;
    a->size = max;
    b->size = max;

    int cnt = 0;
    int idx = 0;
    for (int iter = 0; iter < q; iter++)
    {
        int num = prime[iter];

        for (int j = max - 1; j >= 0; j--)
        {
            if (number[j] % num == 0)
            {
                push(b, number[j]);
            }
            else
            {
                push(a, number[j]);
            }
        }
        while (b->top >= 0)
        {
            answer[cnt++] = pop(b);
        }

        int temp[max]; // Temporary array to store elements in correct order
        int idx = 0;

        // Pop elements from `A` and store them in `temp`
        while (a->top >= 0)
        {
            temp[idx++] = pop(a);
        }

        // Restore original order in `number[]`
        for (int i = 0; i < idx; i++)
        {
            number[i] = temp[idx - 1 - i]; // Reverse back to correct order
        }
        max = idx; // Update max for next iteration
    }
    for (int i = max - 1; i >= 0; i--)
    {
        answer[cnt++] = number[i]; // Append in reverse order
    }

    *result_count = cnt;
    return answer;
}