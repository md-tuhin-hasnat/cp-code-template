#include <bits/stdc++.h>
using namespace std;

struct Node {
    int u, dis;
    
    Node(int iU, int iDis) {
        u = iU;
        dis = iDis;
    }
    
    bool operator<(const Node& b) const {
        return dis > b.dis;
    }
};

const int Vertex_N = 100005;
const int oo = 1e8;

int dist[Vertex_N];
int par[Vertex_N];
vector<int> graph[Vertex_N];
vector<int> weight[Vertex_N];

void init(int n) {
    for(int i = 1; i <= n; i++) {
        dist[i] = oo;
        par[i] = -1;
        graph[i].clear();
        weight[i].clear();
    }
}

int dijkstra(int source, int destination) {
    priority_queue<Node> pq;
    
    dist[source] = 0;
    pq.push(Node(source, 0));
    
    while(!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        
        int u = cur.u;
        int uDist = cur.dis;
        
        if(dist[u] < uDist) {
            continue;
        }
        
        for(int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            int edgeWeight = weight[u][i];
            
            if(dist[v] > uDist + edgeWeight) {
                dist[v] = uDist + edgeWeight;
                par[v] = u;
                pq.push({v, dist[v]});
            }
        }
    }
    
    return dist[destination];
}

vector<int> getPath(int source, int destination) {
    int v = destination;
    vector<int> path;
    
    while(source != v) {
        path.push_back(v);
        v = par[v];
    }
    
    path.push_back(source);
    reverse(path.begin(), path.end());
    
    return path;
}
