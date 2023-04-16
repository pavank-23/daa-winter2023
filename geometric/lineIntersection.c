#include <stdio.h>

struct point
{
    int x, y;
};

int max(int x, int y)
{
    return (x > y);
}

int min(int x, int y)
{
    return (x < y);
}

int direction(struct point p, struct point q, struct point r)
{
    int val = (p.x - r.x) * (q.y - r.y) - (q.x - r.x) * (p.y - r.y);
    return val;
}

int onSegment(struct point p1, struct point p2, struct point p)
{
    return (p.x <= max(p1.x, p2.x) && p.x >= min(p1.x, p2.x) && p.x <= max(p1.y, p2.y) && p.x >= min(p1.y, p2.y));
}

int lineIntersection(struct point p1, struct point p2, struct point p3, struct point p4)
{
    int d1 = direction(p3, p4, p1);
    int d2 = direction(p3, p4, p2);
    int d3 = direction(p1, p2, p3);
    int d4 = direction(p1, p2, p4);
    if (((d1 < 0) && (d2 > 0)) || (((d1 > 0) && (d2 < 0))) || (((d3 < 0) && (d4 > 0))) || (((d4 < 0) && (d3 > 0))))
        return 1;
    if (d1 == 0 && onSegment(p3, p4, p1))
        return 1;
    if (d2 == 0 && onSegment(p3, p4, p2))
        return 1;
    if (d3 == 0 && onSegment(p1, p2, p3))
        return 1;
    if (d4 == 0 && onSegment(p1, p2, p4))
        return 1;
    return 0;
}

int main()
{
    // struct point p1 = {1, 1};
    // struct point q1 = {10, 1};
    // struct point p2 = {1, 2};
    // struct point q2 = {10, 2};

    // lineIntersection(p1, q1, p2, q2) ? printf("Yes\n") : printf("No\n");

    // struct point p2 = {0, 0};
    // struct point q2 = {10, 10};
    // struct point q1 = {0, 10};
    // struct point p1 = {10, 0};

    // lineIntersection(p1, q1, p2, q2) ? printf("Yes\n") : printf("No\n");
    struct point p2 = {1, 1};
    struct point q2 = {10, 10};
    struct point q1 = {0, 0};
    struct point p1 = {-5, -5};

    if (lineIntersection(p1, q1, p2, q2))
        printf("Yes");
    else
        printf("No");
}