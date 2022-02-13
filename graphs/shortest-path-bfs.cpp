
/**
 * @file bridges.cpp
 * @author Jatin Narula(jatin.jt.narula@gmail.com)
 * @brief This program finds the shortest path in a unit weight undirected graph. Time complexity : O(v + e)
 * @version 0.1
 * @date 2022-02-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

void BFS(vector<int> adj[], int N, int src) 
{ 
	int dist[N];
	for(int i = 0;i<N;i++) dist[i] = INT_MAX; 
	queue<int>  q;
	
	dist[src] = 0;
	q.push(src); 

	while(q.empty()==false) 
	{ 
		int node = q.front(); 
		q.pop();
		 
		for(auto it:adj[node]){
		    if(dist[node] + 1 < dist[it]){
		        dist[it]=dist[node]+1;
		        q.push(it);
		    }
		} 
	} 
	for(int i = 0;i<N;i++) cout << dist[i] << " "; 
	
} 