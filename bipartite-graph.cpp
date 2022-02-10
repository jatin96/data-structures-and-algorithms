#include<bits/stdc++.h>
using namespace std;
vector <int> graph[10005];
int n, m;
COLOR coloring[100007];
enum COLOR { White, Black, Uncolored };
bool isBipartite(int node) {
    if (coloring[node] == Uncolored)
        coloring[node] = White;
    
    for (int i = 0; i < graph[node].size(); i++) {
        int child = graph[node][i];
        if (coloring[child] == Uncolored) {
            coloring[child] = coloring[node] == White ? Black : White;
            if (!isBipartite(node))
                return false;
        } 
        else if (coloring[child] == coloring[node])
            return false;
    }

    return true;
}
int main() {
    
    cin >> n >> m;
	for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
    }

    cout << "Is the graph bipartite? : " << isBipartite(0) << endl;
    return 0;
}