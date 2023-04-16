#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define e 2.71828

int roundNo(float num)
{
    return num < 0 ? num - 0.5 : num + 0.5;
}

void printBestCandidate(int candidate[], int n)
{
    int sample_size = roundNo(n / e);
    int best = 0;
    for (int i = 1; i < sample_size; i++)
        if (candidate[i] > candidate[best])
            best = i;
    for (int i = sample_size; i < n; i++)
        if (candidate[i] >= candidate[best])
        {
            best = i;
            break;
        }
    if (best >= sample_size)
        printf("Best candidate: %d", candidate[best]);
    else
        printf("No best candidate");
}

int main()
{
    int n = 8;
    int candidate[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        candidate[i] = 1 + rand() % 8;
        printf("%d\n", candidate[i]);
    }
    printBestCandidate(candidate, n);

    return 0;
}