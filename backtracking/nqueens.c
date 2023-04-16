#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool queenPlace(int k, int i, int x[])
{
    for (int j = 0; j < k; j++)
    {
        if ((x[j] == i) || abs(x[j] - i) == abs(j - k))
        {
            return false;
        }
    }
    return true;
}

void nQueens(int k, int n, int x[])
{
    for (int i = 0; i < n; i++)
    {
        if (queenPlace(k, i, x))
        {
            x[k] = i;
            if (k == n)
            {
                for (int j = 0; j < n; j++)
                {
                    printf("%d ", x[j]);
                }
                printf("\n");
            }
            else
            {
                nQueens(k + 1, n, x);
            }
        }
    }
}

int main()
{
    int x[4] = {0, 0, 0, 0};
    nQueens(4, 4, x);
}