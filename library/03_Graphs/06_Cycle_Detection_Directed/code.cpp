#include <bits/stdc++.h>
using namespace std;

const int SZ = 100005;
vector<int> g[SZ];
int vis[SZ];
int pathvis[SZ];

void init(int V) {
    for(int i = 1; i <= V; i++) {
        pathvis[i] = 0;
        vis[i] = 0;
        g[i].clear();
    }
}

bool dfs(int u, int par) {
    vis[u] = 1;
    pathvis[u] = 1;
    
    for(auto v : g[u]) {
        if(vis[v] == 0) {
            if(dfs(v, u) == true)
                return true;
        }
        else if(pathvis[v]) {
            return true;
        }
    }
    
    pathvis[u] = 0;
    return false;
}

bool hasCycleDirected(int V) {
    for(int i = 1; i <= V; i++) {
        if(vis[i] == 0) {
            if(dfs(i, i) == true) {
                return true;
            }
        }
    }
    return false;
}
