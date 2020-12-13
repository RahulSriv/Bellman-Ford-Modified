#include <stdio.h>
#include <stdlib.h>
#define INT_MAX +2147483647
void BellmanFord(int graph[][3], int V, int E, int src)
{
    int c;
    int dis[V];
    for (int i = 0; i < V; i++)
        dis[i] = INT_MAX;
    dis[src] = 0;
    int i, j;
    // Running the BellmanFord algo for |V|-1 times
    for (i = 0; i < V - 1; i++)
    {
        c = 1; //Variable to check if all dist values are similar to previous loop
        for (j = 0; j < E; j++)
        {
            if (dis[graph[j][0]] + graph[j][2] < dis[graph[j][1]])
            {
                dis[graph[j][1]] =
                    dis[graph[j][0]] + graph[j][2];
                c = 0;
            }
        }
        if (c)
            break;
    }

    // Implementation of the negative cycle rule
    for (i = 0; i < E; i++)
    {
        int x = graph[i][0];
        int y = graph[i][1];
        int weight = graph[i][2];
        if (dis[x] != INT_MAX &&
            dis[x] + weight < dis[y])
            printf("Graph contains negative weight cycle\n");
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t\t%d\n", i, dis[i]);
}

int main()
{
    int V = 5;
    int E = 8;

    // Every edge has three values (u, v, w) where the edge is from vertex u to v.
    //with the weight/length of the edge being w.

    int graph[][3] = {{0, 1, -1}, {0, 4, 4}, {1, 2, -4}, {1, 3, 2}, {2, 4, 2}, {3, 0, 5}, {3, 1, 1}, {4, 3, -3}};

    BellmanFord(graph, V, E, 0);
    return 0;
}