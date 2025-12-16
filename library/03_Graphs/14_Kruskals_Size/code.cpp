#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    
    Edge(int ui, int vi, int wi) {
        u = ui;
        v = vi;
        w = wi;
    }
};

vector<Edge> edgeList;
vector<int> parent;
vector<int> compoSize;

void init(int V) {
    edgeList.clear();
    compoSize.resize(V + 5, 1);
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

void joinComponents(int u, int v) {
    int u_parent = findRoot(u);
    int v_parent = findRoot(v);
    
    if(u_parent == v_parent)
        return;
        
    if(compoSize[u_parent] > compoSize[v_parent]) {
        parent[v_parent] = u_parent;
        compoSize[u_parent] += compoSize[v_parent];
    }
    else {
        parent[u_parent] = v_parent;
        compoSize[v_parent] += compoSize[u_parent];
    }
}

bool compareByWeight(Edge a, Edge b) {
    return a.w < b.w;
}

int kruskal() {
    int cost = 0;
    sort(edgeList.begin(), edgeList.end(), compareByWeight);
    
    for(int i = 0; i < edgeList.size(); i++) {
        if(findRoot(edgeList[i].u) != findRoot (edgeList[i].v)) {
            joinComponents(edgeList[i].u, edgeList[i].v);
            cost += edgeList[i].w;
        }
    }
    return cost;
}
