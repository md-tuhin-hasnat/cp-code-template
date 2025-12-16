#include <bits/stdc++.h>
using namespace std;

const int Size = 100005;
struct Node {
    int idx, st, fin;
};

Node Time[Size];
vector<int> adj[Size];
vector<int> radj[Size];
vector<int> component[Size];
int vis[Size], scc[Size], ti, mrk;

bool compareByFinTime(Node a, Node b) {
    return a.fin > b.fin;
}

void dfs(int u) {
    Time[u].st = ti++;
    vis[u] = 1;
    for(auto v : adj[u]) {
        if(vis[v] == 0) {
            dfs(v);
        }
    }
    Time[u].fin = ti++;
}

void rdfs(int u, int mark) {
    vis[u] = 1;
    scc[u] = mark;
    component[mark].push_back(u);
    for(auto v : radj[u]) {
        if(vis[v] == 0) {
            rdfs(v, mark);
        }
    }
}

void kosarajuSCC(int V) {
    ti = 1;
    for(int i = 1; i <= V; i++) {
        Time[i].idx = i;
        if(vis[i] == 0) {
            dfs(i);
        }
    }
    
    memset(vis, 0, sizeof vis);
    mrk = 1;
    sort(&Time[1], &Time[V + 1], compareByFinTime);
    
    for(int i = 1; i <= V; i++) {
        if(vis[Time[i].idx] == 0) {
            rdfs(Time[i].idx, mrk);
            mrk++;
        }
    }
}
