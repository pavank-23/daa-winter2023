#include <stdio.h>
#include <stdlib.h>

int min(int x, int y)
{
    return (x < y) ? x : y;
}

int als(int t[][4], int a[][4], int *e, int *x)
{
    int f[2][4];
    f[0][0] = e[0] + a[0][0];
    f[1][0] = e[1] + a[1][0];
    for (int i = 1; i < 4; i++)
    {
        f[0][i] = min(f[0][i - 1] + a[0][i], f[1][i - 1] + t[0][i] + a[0][i]);
        f[1][i] = min(f[1][i - 1] + a[1][i], f[0][i - 1] + t[1][i] + a[1][i]);
    }
    return min(f[0][3] + x[0], f[1][3] + x[1]);
}
// int als(int a[][4], int t[][4], int *e, int *x)
// {
//     int first, second, i;
//     first = e[0] + a[0][0];
//     second = e[1] + a[1][0];
//     for (i = 1; i < 4; ++i)
//     {
//         int up = min(first + a[0][i],
//                      second + t[1][i] +
//                          a[0][i]);
//         int down = min(second + a[1][i],
//                        first + t[0][i] +
//                            a[1][i]);
//         first = up;
//         second = down;
//     }

//     // Consider exit times and
//     // return minimum
//     return min(first + x[0],
//                second + x[1]);
// }

int main()
{
    int a[][4] = {{4, 5, 3, 2},
                  {2, 10, 1, 4}};
    int t[][4] = {{0, 7, 4, 5},
                  {0, 9, 2, 8}};
    int e[] = {10, 12}, x[] = {18, 7};
    // int **a = malloc(2 * sizeof(int *));
    // int **t = malloc(2 * sizeof(int));
    // for (int i = 0; i < 2; i++)
    // {
    //     a[i] = malloc(4 * sizeof(int));
    //     t[i] = malloc(4 * sizeof(int));
    // }
    // a[0][0] = 4;
    // a[0][1] = 5;
    // a[0][2] = 3;
    // a[0][3] = 2;
    // a[1][0] = 2;
    // a[1][1] = 10;
    // a[1][2] = 1;
    // a[1][4] = 4;
    // t[0][0] = 0;
    // t[0][1] = 7;
    // t[0][2] = 4;
    // t[0][3] = 5;
    // t[1][0] = 0;
    // t[1][1] = 9;
    // t[1][2] = 2;
    // t[1][4] = 8;
    // int e[] = {10, 12}, x[] = {18, 7};
    printf("%d ", als(t, a, e, x));
}