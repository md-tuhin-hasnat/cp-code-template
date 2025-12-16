#include <bits/stdc++.h>
using namespace std;

const int nodes = 100005;
int timer;
int vis[nodes], tin[nodes], tlow[nodes];
vector<int> adj[nodes];
vector<pair<int,int>> bridges;

void bridgeDFS(int node, int parent) {
    vis[node] = 1;
    tin[node] = tlow[node] = timer++;
    
    for(auto v : adj[node]) {
        if(v == parent) continue;
        if(vis[v] == 0) {
            bridgeDFS(v, node);
            tlow[node] = min(tlow[v], tlow[node]);
            if(tlow[v] > tin[node]) {
                bridges.push_back({node, v});
            }
        } else {
            tlow[node] = min(tlow[v], tlow[node]);
        }
    }
}

void init(int V) {
    for(int i = 0; i <= V; i++) {
        vis[i] = 0;
        adj[i].clear();
    }
    bridges.clear();
    timer = 1;
}
