#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100005;

vector<int> adj[SIZE];
int color[SIZE];

bool DFS(int u, int col) {
    color[u] = col;
    
    for(auto v : adj[u]) {
        if(color[v] == -1) {
            if(DFS(v, !col) == false)
                return false;
        }
        else if(color[v] == col) {
            return false;
        }
    }
    return true;
}

void init(int V) {
    for(int i = 0; i <= V; i++) {
        color[i] = -1;
        adj[i].clear();
    }
}

bool isBipartite(int V) {
    for(int i = 1; i <= V; i++) {
        if(color[i] == -1) {
            if(DFS(i, 0) == false) {
                return false;
            }
        }
    }
    return true;
}
