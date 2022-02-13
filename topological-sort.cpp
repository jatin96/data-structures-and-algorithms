#include<bits/stdc++.h>
using namespace std;
vector<int> graph[10005];
int n, m;
int indegree[100007] = {};
int main() {
    cin >> n >> m;
    queue<int> Q;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        indegree[v]++;
        graph[u].push_back(v);
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
        Q.push(i);
    }
    vector<int> res;
    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();
        res.push_back(node);
        for (int i = 0; i < graph[node].size(); i++) {
            int child = graph[node][child];
            indegree[child]--;
            if (indegree[child] == 0)
            Q.push(child);
        }
    }

    cout << "Topological sort : " << endl;
    for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";

    return 0;

}