#include<bits/stdc++.h>
using namespace std;
vector <int> graph[10005];
vector<bool> vis(10007, false);
vector<int> lowestTime(100007, -1);
vector<int> insertionTime(100007, -1);

int n, m;

void dfs(int node, int parent, int timer) {
    vis[node] = true;
    lowestTime[node] = insertionTime[node] = timer++;
    for (int i = 0; i < graph[node].size(); i++) {
        int child = graph[node][i];
        if (!vis[child]) {
            dfs(child, node, timer);
            lowestTime[node] = min(lowestTime[node], lowestTime[child]);
            if (lowestTime[child] > insertionTime[node])
             cout << node << " " << child << endl;
        } else {
            lowestTime[node] = min(lowestTime[node], insertionTime[child]);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(0, -1, 0);
        }
    }

    return 0;
}