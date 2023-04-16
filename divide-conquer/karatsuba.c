#include <stdio.h>
#include <math.h>

int max(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}

int karatsuba(int num1, int num2)
{
    if ((num1 < 10) || (num2 < 10))
    {
        return num1 * num2;
    }
    else
    {
        int m = max((int)(log10(num1) + 1), (int)(log10(num2) + 1));
        int m2 = floor(m / 2);
        printf("%d ", m);
        int low1 = num1 % (int)(pow(10, m2));
        int high1 = num1 / pow(10, m2);
        int low2 = num2 % (int)(pow(10, m2));
        int high2 = num2 / pow(10, m2);

        int z0 = karatsuba(low1, low2);
        int z1 = karatsuba(low1 + high1, low2 + high2);
        int z2 = karatsuba(high1, high2);

        return (z2 * (pow(10, (m2 * 2))) + ((z1 - z2 - z0) * (pow(10, m2))) + z0);
    }
}

int main()
{
    printf("%d", karatsuba(12, 13));
}