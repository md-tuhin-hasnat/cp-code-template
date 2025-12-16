#include <bits/stdc++.h>
using namespace std;

vector<int> Rank, parent;

void init(int V) {
    Rank.resize(V + 5, 0);
    parent.resize(V + 5);
    
    for(int i = 0; i <= V; i++) {
        parent[i] = i;
    }
}

int findRoot(int node) {
    if(node == parent[node])
        return node;
    return parent[node] = findRoot(parent[node]);
}

void unionByRank(int u, int v) {
    int u_parent = findRoot(u);
    int v_parent = findRoot(v);
    
    if(u_parent == v_parent)
        return;
        
    if(Rank[u_parent] > Rank[v_parent]) {
        parent[v_parent] = u_parent;
    }
    else if(Rank[u_parent] < Rank[v_parent]) {
        parent[u_parent] = v_parent;
    }
    else {
        parent[v_parent] = u_parent;
        ++Rank[u_parent];
    }
}
