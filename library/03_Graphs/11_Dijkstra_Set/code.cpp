#include <bits/stdc++.h>
using namespace std;

const int Size = 100005;
const int oo = 2e9;

set<pair<int,int>> st;
vector<int> adj[Size];
vector<int> weight[Size];
int par[Size], dist[Size];

void init(int V) {
    for(int i = 0; i < V + 5; i++) {
        adj[i].clear();
        weight[i].clear();
        dist[i] = oo;
        par[i] = i;
    }
    st.clear();
}

void dijkstra(int s) {
    dist[s] = 0;
    st.insert({0, s});
    
    while(!st.empty()) {
        auto it = *(st.begin());
        int u = it.second;
        int udis = it.first;
        st.erase(it);
        
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            int vw = weight[u][i];
            
            if(dist[v] > udis + vw) {
                if(dist[v] != oo) {
                    st.erase({dist[v], v});
                }
                
                par[v] = u;
                dist[v] = udis + vw;
                st.insert({dist[v], v});
            }
        }
    }
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
