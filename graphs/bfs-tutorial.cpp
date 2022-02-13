// Jatin Narula (jatin.jt.narula)
#include <bits/stdc++.h>
using namespace std;
#define ms(a ,value) memset(a ,value,sizeof(a))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define finderror1(x) cout<<#x<<" --> "<<x<<"\n";
#define finderror2(x,y) cout<<#x<<" --> "<<x<<"\t"<<#y<<" --> "<<y<<"\n";
#define finderror3(x,y,z) cout<<#x<<" --> "<<x<<"\t"<<#y<<" --> "<<y<<"\t"<<#z<<" --> "<<z<<"\n";
const double PI=3.1415926535897;
const int N=26;
typedef long long int ll;
int main() {
    queue < pair <int, int> > Q;
    bool visited[10007] = {false};
    vector < int > g[10007]; // array of vectors g[i] --> this gives me the list of neighbours of i node
    int N, E; // number of nodes and edges respectively
    cin >> N >> E;
    for(int i = 0; i < E; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int st, en;
    cout << "the nodes between which the shortest path we need to find\n";
    cin >> st >> en;
    
    Q.push({st,0});
    visited[st] = true;

    while(!Q.empty()) {
        int u = Q.front().first;
        int dist = Q.front().second;
        Q.pop();
        if(u == en) {
            cout << "the shortest distance is " << dist << "\n";
            break;
        }
        int siz = g[u].size();
        for(int i = 0; i < siz; i++) {
            int v = g[u][i];
            if(visited[v] == false) {
                Q.push({v, dist + 1});
                visited[v] = true;
            }
        }
    }
    return 0;
}