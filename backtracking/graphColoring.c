#include <stdbool.h>
#include <stdio.h>

#define V 6

bool isSafe(int v, bool graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool nextValue(bool graph[V][V], int m, int color[], int v)
{
    if (v == V)
        return true;
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;
            if (nextValue(graph, m, color, v + 1) == true)
                return true;

            color[v] = 0;
        }
    }
    return false;
}

bool mColoring(bool graph[V][V], int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (nextValue(graph, m, color, 0) == false)
    {
        printf("Solution does not exist");
        return false;
    }
    for (int i = 0; i < V; i++)
        printf(" %d ", color[i]);
    printf("\n");
    return true;
}

int main()
{
    bool graph[V][V] = {
        {0, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 0, 1},
        {1, 1, 0, 1, 1, 0},
        {0, 1, 1, 0, 0, 1},
        {1, 0, 1, 0, 0, 1},
        {0, 1, 0, 1, 1, 0}};
    int m = 3;
    mColoring(graph, m);
    return 0;
}