#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define V 6

void initAdjMatrix(int arr[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            arr[i][j] = 0;
        }
    }
}

void addEdge(int arr[][V], int x, int y, int w)
{
    arr[x][y] = w;
}

bool BFS(int adjM[][V], int s, int t, int parent[])
{
    int queue[V];
    int visited[V];
    for (int i = 0; i < V; i++)
    {
        queue[i] = -1;
        visited[i] = 0;
    }
    int rear = -1;
    int front = 0;
    queue[++rear] = s;
    visited[s] = 1;
    int x;
    // printf("Breadth First Search\n");
    while (!(rear < front))
    {
        x = queue[front++];
        // printf("Visited : %d\n", x);
        for (int i = 0; i < V; i++)
        {
            if ((adjM[x][i] > 0) && (visited[i] != 1))
            {
                if (i == t)
                {
                    parent[i] = x;
                    return true;
                }
                queue[++rear] = i;
                parent[i] = x;
                visited[i] = 1;
            }
        }
    }
    return false;
}

void edmondsKarp(int graph[V][V], int s, int t)
{
    int flow = 0;
    int pi[V];
    int u, v;
    int rGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];
    while (BFS(rGraph, s, t, pi))
    {
        printf("YES\n");
        int path_flow = INT_MAX;
        for (v = t; v != s; v = pi[v])
        {
            u = pi[v];
            path_flow = (path_flow < rGraph[u][v]) ? path_flow : rGraph[u][v];
        }
        for (v = t; v != s; v = pi[v])
        {
            u = pi[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        flow += path_flow;
    }
    printf("Maximum possible flow is %d\n", flow);
}

int main()
{
    int graph[V][V] = {{0, 16, 13, 0, 0, 0}, {0, 0, 10, 12, 0, 0}, {0, 4, 0, 0, 14, 0}, {0, 0, 9, 0, 0, 20}, {0, 0, 0, 7, 0, 4}, {0, 0, 0, 0, 0, 0}};
    edmondsKarp(graph, 0, 5);
}
