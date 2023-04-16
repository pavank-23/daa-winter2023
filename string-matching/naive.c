#include <stdio.h>
#include <string.h>

void naiveStringMatching(char *t, char *p)
{
    int m = strlen(p);
    int n = strlen(t);
    for (int i = 0; i < n - m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (t[i + j] != p[j])
            {
                break;
            }
            if (j == m - 1)
            {
                printf("String match at %d ", i);
            }
        }
    }
}

int main()
{
    naiveStringMatching("abcdadaeda", "dae");
}