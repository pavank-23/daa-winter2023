#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int printOptimal(int **s, int i, int j)
{
    if (i == j)
        printf("A%d", i);
    else
    {
        printf("(");
        printOptimal(s, i, s[i][j]);
        printOptimal(s, s[i][j] + 1, j);
        printf(")");
    }
}

int mcm(int *p, int n)
{
    // int min = INT_MAX;
    int count;
    int **s = malloc(n * sizeof(int *));
    int **m = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        s[i] = malloc(n * sizeof(int));
        m[i] = malloc(n * sizeof(int));
    }
    for (int x = 0; x < n; x++)
    {
        m[x][x] = 0;
    }
    for (int x = 2; x <= n; x++)
    {
        for (int i = 1; i < n - x + 1; i++)
        {
            int j = i + x - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                count = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (m[i][j] > count)
                {
                    m[i][j] = count;
                    s[i][j] = k;
                }
            }
        }
    }
    printOptimal(s, 1, n - 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    return m[1][n - 1];
}

int main()
{
    int p[] = {30, 35, 15, 5, 10, 20};
    printf("%d ", mcm(p, 6));
}