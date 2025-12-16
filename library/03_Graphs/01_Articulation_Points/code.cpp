#include <bits/stdc++.h>
using namespace std;

const int nodes = 100005;
int timer;
int vis[nodes], tin[nodes], tlow[nodes];
vector<int> adj[nodes];
set<int> art_points;

void artPointDFS(int node, int parent) {
    vis[node] = 1;
    tin[node] = tlow[node] = timer++;
    int child = 0;
    
    for(auto v : adj[node]) {
        if(v == parent) continue;
        if(vis[v] == 0) {
            artPointDFS(v, node);
            tlow[node] = min(tlow[v], tlow[node]);
            if(tlow[v] >= tin[node] && parent != -1) {
                art_points.insert(node);
            }
            child++;
        } else {
            tlow[node] = min(tin[v], tlow[node]);
        }
    }
    if(child > 1 && parent == -1) {
        art_points.insert(node);
    }
}

void init(int V) {
    for(int i = 0; i <= V; i++) {
        vis[i] = 0;
        adj[i].clear();
    }
    art_points.clear();
    timer = 1;
}
