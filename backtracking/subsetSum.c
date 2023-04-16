#include <stdio.h>

void subsetSum(int sum, int k, int r, int x[], int w[], int m, int n)
{
    x[k] = 1;
    if (sum + w[k] == m)
    {
        for (int i = 0; i <= k; i++)
        {
            printf("%d ", x[i]);
        }
    }
    else if (sum + w[k] + w[k + 1] <= m)
    {
        subsetSum(sum + w[k], k + 1, r - w[k], x, w, m, n);
    }
    if ((sum + r - w[k] >= m) && (sum + w[k + 1] <= m))
    {
        x[k] = 0;
        subsetSum(sum, k + 1, r - w[k], x, w, m, n);
    }
}

int main()
{
    int sum = 0;
    int w[4] = {3, 4, 5, 6};
    int m = 13;
    int x[4] = {0, 0, 0, 0};
    int k = 0;
    int r = 18;
    subsetSum(sum, k, r, x, w, m, 4);
}