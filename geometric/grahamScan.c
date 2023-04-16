#include <stdio.h>
#include <stdlib.h>

#define size 5

struct Point
{
    int x, y;
};

struct Point S[size];
int top = -1;
void push(struct Point x)
{
    if (top == size - 1)
    {
        printf("Stack Overflow");
    }
    else
    {
        top++;
        S[top] = x;
    }
}

struct Point pop()
{
    struct Point del_e;
    if (top == -1)
    {
        printf("Stack Empty");
        del_e.x = -1;
        del_e.y = -1;
    }
    else
    {
        del_e = S[top];
        top--;
    }
    return del_e;
}

struct Point p0;

struct Point nextToTop(struct Point *S)
{
    struct Point p = S[top];
    pop();
    struct Point res = S[top];
    push(p);
    return res;
}

int swap(struct Point p1, struct Point p2)
{
    struct Point temp = p1;
    p1 = p2;
    p2 = temp;
}

int empty()
{
    return (top == -1) ? 1 : 0;
}

int distSq(struct Point p1, struct Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y);
}

int orientation(struct Point p, struct Point q, struct Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

int compare(const void *vp1, const void *vp2)
{
    struct Point *p1 = (struct Point *)vp1;
    struct Point *p2 = (struct Point *)vp2;
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;
    return (o == 2) ? -1 : 1;
}

void convexHull(struct Point points[], int n)
{
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y &&
                           points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }
    swap(points[0], points[min]);
    p0 = points[0];
    qsort(&points[1], n - 1, sizeof(struct Point), compare);
    int m = 1;
    for (int i = 1; i < n; i++)
    {
        while (i < n - 1 && orientation(p0, points[i],
                                        points[i + 1]) == 0)
            i++;
        points[m] = points[i];
        m++;
    }
    if (m < 3)
        return;
    push(points[0]);
    push(points[1]);
    push(points[2]);
    for (int i = 3; i < m; i++)
    {
        while (orientation(nextToTop(S), S[top], points[i]) != 2)
            pop();
        push(points[i]);
    }
    while (!empty())
    {
        struct Point p = S[top];
        printf("(%d, %d)\n", p.x, p.y);
        pop();
    }
}

int main()
{
    struct Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    convexHull(points, n);
    return 0;
}