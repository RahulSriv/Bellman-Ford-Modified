/* 

Bellman Ford algorithm helps us find the shortest path from a vertex to all other
vertices of a weighted graph. It is similar to Dijkstra's algorithm but it can work with
graphs in which edges can have negative weights.

Though it is slower than Dijkstra's algorithm,
Bellman-Ford is capable of handling graphs that contain negative edge weights, so
it is more versatile. It is worth noting that if there exists a negative cycle in the
graph, then there is no shortest path. Going around the negative cycle an infinite
number of times would continue to decrease the cost of the path (even though the
path length is increasing). Because of this, Bellman Ford can also be used to detect
negative cycles which is a useful feature.

*/

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

/* 

Using Bellman-Ford algorithm, we can detect if there is a negative cycle in our
graph. We know that, to find out the shortest path, we need to relax all the edges
of the graph (V-1) times, where V is the number of vertices in a graph.

If there is a negative cycle in a graph, even after (V-1) iterations, we can update d[].
This happens because for every iteration, traversing through the negative cycle
always decreases the cost of the shortest path. This is why Bellman Ford algorithm
limits the number of iterations to (V-1). If we used Dijkstra's Algorithm here, we'd
be stuck in an endless loop.

*/    
    
    
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
