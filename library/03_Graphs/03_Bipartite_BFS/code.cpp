#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100005;

vector<int> adj[SIZE];
int color[SIZE];

bool BFS(int s) {
    color[s] = 0;
    queue<int> Q;
    Q.push(s);
    
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        
        for(auto v : adj[u]) {
            if(color[v] == -1) {
                color[v] = !color[u];
                Q.push(v);
            }
            else if(color[v] == color[u]) {
                return false;
            }
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
            if(BFS(i) == false) {
                return false;
            }
        }
    }
    return true;
}
