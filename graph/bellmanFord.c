#include <stdio.h>
#include <stdlib.h>

void initAdjMatrix(int **arr)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = 0;
        }
    }
}

void addEdge(int **arr, int x, int y, int w)
{
    arr[x][y] = w;
}

void bellmanFord(int **adjM, int V, int s)
{
    int d[V];
    int pi[V];
    for (int i = 0; i < V; i++)
    {
        d[i] = __INT_MAX__;
        pi[i] = 99999;
    }
    d[s] = 0;
    pi[s] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (int u = 0; u < V; u++)
        {
            for (int v = 0; v < V; v++)
            {
                if (adjM[u][v] != 0)
                {
                    if (d[v] > d[u] + adjM[u][v])
                    {
                        d[v] = d[u] + adjM[u][v];
                        pi[v] = u;
                    }
                }
            }
        }
    }

    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            if (adjM[u][v] != 0)
            {
                if (d[v] > d[u] + adjM[u][v])
                {
                    printf("Negative Cycle exists");
                    break;
                }
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        printf("%d ", d[i]);
    }
}

int main()
{
    int **arr = malloc(4 * sizeof(int *));
    for (int i = 0; i < 4; i++)
    {
        arr[i] = malloc(4 * sizeof(int));
    }
    initAdjMatrix(arr);
    addEdge(arr, 0, 1, -3);
    addEdge(arr, 1, 2, 1);
    // addEdge(arr, 2, 3, 2);
    addEdge(arr, 3, 0, 1);
    addEdge(arr, 1, 3, 2);
    addEdge(arr, 2, 3, 2);
    bellmanFord(arr, 4, 0);
}