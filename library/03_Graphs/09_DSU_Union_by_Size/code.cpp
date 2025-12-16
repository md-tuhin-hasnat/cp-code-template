#include <bits/stdc++.h>
using namespace std;

vector<int> Size, parent;

void init(int V) {
    Size.resize(V + 5, 1);
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

void unionBySize(int u, int v) {
    int u_parent = findRoot(u);
    int v_parent = findRoot(v);
    
    if(u_parent == v_parent)
        return;
        
    if(Size[u_parent] > Size[v_parent]) {
        parent[v_parent] = u_parent;
        Size[u_parent] += Size[v_parent];
    }
    else {
        parent[u_parent] = v_parent;
        Size[v_parent] += Size[u_parent];
    }
}
