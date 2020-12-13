# Bellman-Ford-Modified
Bellman Ford algorithm helps us find the shortest path from a vertex to all other vertices of a weighted graph but the algorithm doesn't work well with negative cycles as the weights of the vertices keeps on decreasing even when relaxation has occurred. So here the modified version is presented overcoming this drawback.

Drawbacks of Bellman Ford Algorithm:

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
