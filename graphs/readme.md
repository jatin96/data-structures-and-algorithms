# Graph algorithms revision notes

# Depth First Search

- Time complexity : O(v + e)
- space complexity : O(v)
- implemented using recursion

# Bread First Search

- Time complexity : O(v + e)
- space complexity : O(v)
- implemented using queue

# Topological Sort

- Linear ordering of graph such that if an edge is u -> v, u will occur first in the topological ordering of the graph. This is true for all the edges
- Topological sort only exists for a DAG because if there is cycle then you cannot decide which node should be placed first.
- This is implement using bfs with indegree array. 
- You insert all elements with zero indegree into the queue. 
- pop elements one by one and then decrease the indegree of the adjacent nodes by 1. if the indegree of adjacent node becomes zero, insert it again into the queue.
- repeat this till the array is not empty.
- time complexity : O(v + e) 
- space complexity : O(v)

# bipartite graph
 - if a graph can be divided into two sets such that all the edges have one endpoint in one set and another endpoint in another set, its called a bipartite graph.
 - in other graphs, if you start coloring the graph such that every adjacent node has different color, and you are able to do so using 2 colors then the graph is a bipartite graph.
 - this can be implemented using bfs and dfs. 
 - in bfs, assign a color to the first node inserted into the queue. then check for its adjacent nodes. If the adjacent node is uncolored, color it with a different color. If the adjacent node is colored, then check its color. If the color is same as the parent node, then return false.
 - when the bfs ends, return true because you were able to successfully color the graph.
- in dfs, you color the parent with one color and then check the children. If the children uncolored then you color it with a different color, if the child is already colored with the same color then you return false.
- if the dfs ends, you return true which means you were successfully able to color the entire graph
- time complexity : O(v + e)
- space complexity : O(v)

# Cycle detection in Directed Graph

- Directed graphs have  an issue that it might seem that there is a cycle, but it might not be a cycle just because of the direction of the edges. So you need to keep a current dfsVis array which marks the nodes as visited only in the current visited branch of the dfs, then resets because backtracking.
- you perform normal dfs, but you take another dfsVis array. you mark it as true in the beginning of your dfs call. Then when you are checking for children, if the child is not visited then you visit it. 
- if the child is visited, you check whether it is visited in the current dfs call by using dfsVis[child]. If yes you return true.
- when dfs ends, you reset the dfsvis[node] = false so that its ready for the next call.
- time complexity : O(v + e)
- space complexity : O(v)

# Cycle detection in undirected graph
- you start with normal dfs but you also pass a variable called parent.
- if the child is not visited, you visit it. 
- if the child is visited, you check if child == parent, if yes you return true stating that there is a cycle in the graph.
- time complexity : O(v + e)
- space complexity : O(v)

# Dijikstra's algorithm 
- Dijikstra'a algorithm is used to find the single source shortest path to all the other nodes.
- It can be used for both directed and undirected graphs
- It can be used for both cyclic and acyclic graphs.
- It cannot be used if the there are negative weight cycles in the directed graph. This also means it cannot be applied in an undirected graph with negative weight edges.
- you use a priority queue in this question which contains the cost so far and the node in the queue.
- you also need a distance array to store the min distance. It is initialized with INT_MAX.
- inside bfs you check if the current cost > dist[node] then you continue since you already have a better value.
- If not, you iterate over the children and then insert into the queue a child which gives better dist
```cpp
if ( dist[u] + w <  dist[v]) {
    dist[v] = dist[u] + w;
    Q.push({dist[v], v});
}
``` 
- time complexity : O((V + e)log(v))
- space complexty : O(v)

# Bellman Ford Algorithm
1. Bellman ford can handle negative wight edges in a directed graph which has no negative cycles.
2. Advantage of bellman ford is that it can help you find out that a graph has negative weight cycle or not, but dijikstra cannot.
3. Dijikstra is normally considered better than bellman ford if the edges have positive weights.
4. In bellman ford, you perform relaxation N - 1 times because the longest linear path possible with N nodes can at max contain N - 1 edges.
5. at each relaxation, you have u v w, you do the following : 
```cpp
    dist[src] = 0;
        for(auto it: edges) {
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt; 
            }
        }
```
6. how to detect negative cycle ? Since you know after N - 1 relaxations, you would have the shortest path, you perform 1 more relaxation. If still the dist array reduces at any value, it means there is a negative cycle in the graph.

7. time complexity : O(V^2)
8. space complexity : O(V)

# Shortest path in undirected unit weight graph
- You can use bfs just like dijikstra but with a queue.
- time complexity : O(v + e)
- space complexity : O(v)


# strongly connected components
- strongly connected components in a graph is a component whose all nodes are reachable from all other nodes.
- you can find all the strongly connected components using a three step approach
- firstly find the topological sorting of the graph using dfs.
- then transpose the graph
- then perform dfs on this transposed graph using the stack constructed in toposort
- time complexity : O(v + e)
- space complexity : O(v + e) + O(v)

# prims algorithm
 - prims algorithm finds the minimum spanning tree in a graph.
 - you use a priority queue, mstSet, key/ dist, parent.
 - you push the first element into the queue along with the weight {0,0}
 - inside bfs
 - you mark the popped node as mstSet[node] = true.
 - then you check for all the adjacent nodes of node, 

 ```cpp
 if (mstSet[adj] == false && weight < key[adj]) {
     parent[v] = node;
     key[v] = weight;
     pq.push({key[v], v})
 }
 ```
 - time complexity : O((v + e) log(v))
 - space complexity : O(v)



