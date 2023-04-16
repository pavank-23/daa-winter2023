#include <stdio.h>
#include <string.h>
#include <math.h>

void rabinKarp(char *T, char *P, int d, int q)
{
    int m = strlen(P);
    int n = strlen(T);
    // int h = (int)(pow(d, m - 1)) % q;
    int p = 0;
    int t = 0;
    int i, j;
    int h = 1;
    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;
    for (i = 0; i < m; i++)
    {
        p = (d * p + P[i]) % q;
        t = (d * t + T[i]) % q;
    }
    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (T[i + j] != P[j])
                {
                    break;
                }
            }
            if (j == m)
            {
                printf("Shift at %d", i);
            }
        }
        if (i < n - m)
        {
            t = (d * (t - T[i] * h) + T[i + m]) % q;
            if (t < 0)
                t += q;
        }
    }
}

int main()
{
    rabinKarp("3191093434901012", "10", 10, 13);
}