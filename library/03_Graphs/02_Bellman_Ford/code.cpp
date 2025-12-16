#include <bits/stdc++.h>
using namespace std;

const int V_SZ = 100005;
const int oo = (1 << 25);

struct Edge {
    int u, v, w;
};

vector<Edge> edgeList;
int dist[V_SZ];
int par[V_SZ];

void init(int V) {
    for(int i = 1; i <= V; i++) {
        dist[i] = oo;
        par[i] = -1;
    }
    edgeList.clear();
}

bool bellmanFord(int s, int V) {
    dist[s] = 0;
    bool isUpdated;
    
    for(int i = 1; i <= V; i++) {
        isUpdated = false;
        
        for(auto edg : edgeList) {
            if(dist[edg.v] > dist[edg.u] + edg.w) {
                dist[edg.v] = dist[edg.u] + edg.w;
                par[edg.v] = edg.u;
                isUpdated = true;
            }
        }
    }
    
    return isUpdated;
}
