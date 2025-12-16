#include <bits/stdc++.h>
using namespace std;

const int SZ = 100005;
vector<int> g[SZ];
int vis[SZ];

void init(int V) {
    for(int i = 1; i <= V; i++) {
        vis[i] = 0;
        g[i].clear();
    }
}

bool dfs(int u, int par) {
    vis[u] = 1;
    
    for(auto v : g[u]) {
        if(vis[v] == 0) {
            if(dfs(v, u) == true)
                return true;
        }
        else if(vis[v] && par != v) {
            return true;
        }
    }
    
    return false;
}

bool hasCycleUndirected(int V) {
    for(int i = 1; i <= V; i++) {
        if(vis[i] == 0) {
            if(dfs(i, -1) == true) {
                return true;
            }
        }
    }
    return false;
}
