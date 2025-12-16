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

const int Vertex_N = 100005;

vector<Edge> edgeList;
int rnk[Vertex_N];
int par[Vertex_N];

void init(int n) {
    edgeList.clear();
    
    for(int i = 1; i <= n; i++) {
        rnk[i] = 0;
        par[i] = i;
    }
}

int findSet(int u) {
    if(u != par[u]) {
        par[u] = findSet(par[u]);
    }
    return par[u];
}

void makeLink(int setU, int setV) {
    if(rnk[setU] > rnk[setV]) {
        par[setV] = setU;
    }
    else {
        par[setU] = setV;
        if(rnk[setU] == rnk[setV]) {
            rnk[setV]++;
        }
    }
}

bool compare(Edge &a, Edge &b) {
    return a.w < b.w;
}

int MST_Kruskal() {
    int sum = 0;
    
    sort(edgeList.begin(), edgeList.end(), compare);
    
    for(int i = 0; i < edgeList.size(); i++) {
        if(findSet(edgeList[i].u) != findSet(edgeList[i].v)) {
            sum += edgeList[i].w;
            makeLink(findSet(edgeList[i].u), findSet(edgeList[i].v));
        }
    }
    return sum;
}
