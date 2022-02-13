#include<bits/stdc++.h>
using namespace std;
vector <int> graph[10005];
int n, m;
bool vis[100007] = {false};
bool isCycle(int node,int parent) {
	vis[node] = true;

	for (int i = 0; i < graph[node].size(); i++) {
		int child = graph[node][i];
		if(!vis[child]) {
			if (isCycle(child, node))
				return true;
		}
		else if (child == parent)
			return true;
	}

	return false;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
    }

	return isCycle(0, -1);
	return 0;
}