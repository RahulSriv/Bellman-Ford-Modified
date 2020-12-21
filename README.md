# Modified Bellman-Ford Algorithm
Bellman Ford algorithm helps us find the shortest path from a vertex to all other vertices of a weighted graph but the algorithm doesn't work well with negative cycles as the weights of the vertices keeps on decreasing even when relaxation has occurred. So here the modified version is presented overcoming this drawback.

## Working

Like other Dynamic Programming Problems, the algorithm calculates shortest paths in a bottomup manner. 
It first calculates the shortest distances which have at most one edge in the path.
Then, it calculates the shortest paths with at-most 2 edges, and so on. After the i-th iteration of
the outer loop, the shortest paths with at most i edges are calculated. There can be
maximum |V| - 1 edge in any simple path, that is why the outer loop runs |v| - 1 time. The idea
is, assuming that there is no negative weight cycle, if we have calculated shortest paths with at 
most i edges, then an iteration over all edges guarantees to give shortest path with at-most (i+1)
edge.


## Drawbacks of Bellman Ford Algorithm

1. When no negative weights are present in the graph Bellman Ford has very high time
complexity as it runs in O(VE) time, where V and E are the number of vertices and edges
respectively. ]
2. The approach becomes even slower when a large number of vertices are present in the graph
as in this algorithm each vertex is visited more than once making it infeasible.
3. When an iteration of the main loop of the algorithm terminates without making any changes,
the algorithm still continues, even though the subsequent iterations don’t make any more
changes.
4. Count to infinity if link or node failures render a node unreachable from some set of other
nodes, those nodes may spend forever gradually increasing their estimates of the distance to
it, and in the meantime, there may be routing loops.
5. Changes in network topology are not reflected quickly since updates are spread node-bynode.
6. When a negative cycle is present, the weights of the vertices keeps on decreasing even when
relaxation has occurred |V|-1 times and the algorithm continues forever.


## Suggestive Improvements

1. When no negative edges are present Dijkstra’s approach can be used to reduce the time
complexity to O(V+E).
2. If an iteration of the main loop of the algorithm terminates without making any changes, the
algorithm can be immediately terminated, as subsequent iterations will not make any more
changes. With this early termination condition, the main loop may in some cases use many
fewer than |V| − 1 iterations (even though the worst case of the algorithm remains
unchanged).
3. The standard Bellman-Ford algorithm reports shortest path only if there are no negative
weight cycles as the algorithm continues forever if there is a negative cycle. To avoid this, it
is possible to create a counter that stores how many times a vertex has been relaxed and stop
the algorithm as soon as some vertex got relaxed for the V-th time, so that it reports minimum
distances even if there is a negative weight cycle.
4. We can reduce the number of relaxation steps that need to be performed within each
iteration of the algorithm. If a vertex v has a distance value that has not changed since the
last time the edges out of v were relaxed, then there is no need to relax the edges out of v a
second time. In this way, as the number of vertices with correct distance values grows, the 
number whose outgoing edges that need to be relaxed in each iteration shrinks, leading to a
constant factor savings in time for dense graphs.
