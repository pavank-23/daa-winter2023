#include <stdio.h>
#include <stdlib.h>

struct Point
{
    int x, y;
};

int orientation(struct Point p, struct Point q, struct Point r)
{
    int val = (p.x - q.x) * (r.y - q.y) - (p.y - q.y) * (r.x - q.x);

    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

void convexHull(struct Point *points, int n)
{
    if (n < 3)
        return;
    struct Point *hull = malloc(n * sizeof(struct Point));
    int l = 0;
    for (int i = 0; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;
    int p = l, q, m = 0;
    do
    {
        hull[m] = points[p];
        m++;
        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
        {
            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }
        p = q;

    } while (p != l);
    for (int i = 0; i < m; i++)
        printf("(%d,%d)\n", hull[i].x, hull[i].y);
}

int main()
{
    struct Point points[] = {{3, 0}, {4, 2}, {0, 7}, {4, 4}, {2, 3}, {5, 6}, {2, 8}};
    int n = sizeof(points) / sizeof(points[0]);
    convexHull(points, n);
    return 0;
}
