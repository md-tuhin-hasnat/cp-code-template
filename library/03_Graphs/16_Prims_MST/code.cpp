#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int oo = 1e8;

vector<int> V[100005];
vector<int> W[100005];
int dist[100005], par[100005];
bool vis[100005];

void init(int n) {
    for(int i = 1; i <= n; i++) {
        dist[i] = oo;
        par[i] = -1;
        vis[i] = false;
        V[i].clear();
        W[i].clear();
    }
}

int Prims(int s) {
    int SumDis = 0;
    dist[s] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    pq.push({0, s});
    
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        
        int u = it.second;
        int udis = it.first;
        
        if(dist[u] < udis || vis[u] == true)
            continue;
        
        vis[u] = true;
        SumDis += udis;
        
        for(int i = 0; i < V[u].size(); i++) {
            int v = V[u][i];
            int w = W[u][i];
            
            if(vis[v] == false && dist[v] > w) {
                dist[v] = w;
                par[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    return SumDis;
}
