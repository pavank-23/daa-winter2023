#include <stdio.h>
#include <stdlib.h>

struct item
{
    float profit;
    float weight;
};

int compare(const void *p1, const void *p2)
{
    struct item *a = (struct item *)p1;
    struct item *b = (struct item *)p2;
    return (a->profit / a->weight) < (b->profit / b->weight);
}

void fracKnapsack(int n, struct item *items, int c)
{
    qsort(items, n, sizeof(struct item), compare);
    float sw = 0;
    float sp = 0;
    int i = 0;
    while (i < n)
    {
        if (sw + items[i].weight <= c)
        {
            sw += items[i].weight;
            sp += items[i].profit;
        }
        else
        {
            float frac = (c - sw) / items[i].weight;
            sw += frac * items[i].weight;
            sp += frac * items[i].profit;
        }
        i++;
    }
    printf("Max profit : %f\n", sp);
    printf("Max weight : %f\n", sw);
}

int main()
{
    int n = 5;
    float p[] = {10, 15, 8, 4, 2};
    float w[] = {14, 8, 10, 12, 3};
    int c = 20;
    struct item *items = malloc(n * sizeof(struct item));
    for (int i = 0; i < n; i++)
    {
        items[i].weight = w[i];
        items[i].profit = p[i];
    }
    fracKnapsack(n, items, c);
}