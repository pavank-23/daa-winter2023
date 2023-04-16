#include <stdio.h>
#include <stdlib.h>

#define INF 9999

void initAdjMatrix(int **arr)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == j)
            {
                arr[i][j] = 0;
            }
            else
            {
                arr[i][j] = INF;
            }
        }
    }
}

void addEdge(int **arr, int x, int y, int w)
{
    arr[x][y] = w;
}

void floydWarshall(int **adjM, int V)
{
    int d[V][V];
    int pi[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            // d[i][j] =0;
            // pi[i][j] = 0;
            if (i == j || adjM[i][j] == 0)
            {
                pi[i][j] = INF;
                d[i][j] = 0;
            }
            if (i != j && (adjM[i][j] < INF))
            {
                pi[i][j] = i;
                d[i][j] = adjM[i][j];
            }
        }
    }
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (i != j && d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    pi[i][j] = pi[k][j];
                }
            }
        }
    }
    printf("Distance:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", d[i][j]);
        }
        printf("\n");
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
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    addEdge(arr, 0, 2, -2);
    addEdge(arr, 1, 0, 4);
    addEdge(arr, 1, 2, 3);
    // addEdge(arr, 2, 3, 2);
    addEdge(arr, 2, 3, 2);
    addEdge(arr, 3, 1, -1);
    floydWarshall(arr, 4);
}