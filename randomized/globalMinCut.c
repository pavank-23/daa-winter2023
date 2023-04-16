#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Edge
{
    int src, dest;
};

struct Graph
{
    int V, E;
    struct Edge *edge;
};

struct subset
{
    int parent;
    int rank;
};

int find(struct subset subsets[], int i);
void Union(struct subset subsets[], int x, int y);

int kargerMinCut(struct Graph *graph)
{
    int V = graph->V, E = graph->E;
    struct Edge *edge = graph->edge;
    struct subset *subsets = malloc(sizeof(struct subset) * V);
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    int vertices = V;
    while (vertices > 2)
    {
        int i = rand() % E;
        int subset1 = find(subsets, edge[i].src);
        int subset2 = find(subsets, edge[i].dest);
        if (subset1 == subset2)
            continue;
        else
        {
            printf("Contracting edge %d-%d\n",
                   edge[i].src, edge[i].dest);
            vertices--;
            Union(subsets, subset1, subset2);
        }
    }
    int cutedges = 0;
    for (int i = 0; i < E; i++)
    {
        int subset1 = find(subsets, edge[i].src);
        int subset2 = find(subsets, edge[i].dest);
        if (subset1 != subset2)
            cutedges++;
    }

    return cutedges;
}

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent =
            find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = malloc(sizeof(struct Edge) * E);
    return graph;
}

int main()
{
    int V = 4;
    int E = 5;
    struct Graph *graph = createGraph(V, E);
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;

    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;

    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;

    srand(time(NULL));
    printf("\nCut found by Karger's randomized algo is %d\n", kargerMinCut(graph));

    return 0;
}
