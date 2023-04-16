#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int max(int x, int y)
{
    return (x > y) ? x : y;
}

int lcs(char *s1, char *s2, int m, int n)
{
    int L[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                L[i][j] = 0;
            }
            else if (s1[i] == s2[j])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
            }
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}

int main()
{

    char *S1 = "AGGTAB";
    char *S2 = "GXTXAYB";
    int m = strlen(S1);
    int n = strlen(S2);

    printf("Length of LCS is %d", lcs(S1, S2, m, n));

    return 0;
}
