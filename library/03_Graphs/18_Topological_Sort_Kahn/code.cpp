#include <bits/stdc++.h>
using namespace std;

const int Size = 100005;
vector<int> adj[Size];
vector<int> TS;
int indegree[Size];
queue<int> Q;

void init(int V) {
    for(int i = 0; i <= V; i++) {
        indegree[i] = 0;
        adj[i].clear();
    }
    TS.clear();
}

void BFS() {
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(auto v : adj[u]) {
            --indegree[v];
            if(indegree[v] == 0) {
                TS.push_back(v);
                Q.push(v);
            }
        }
    }
}

vector<int> topologicalSort(int V) {
    for(int i = 1; i <= V; i++) {
        if(indegree[i] == 0) {
            TS.push_back(i);
            Q.push(i);
        }
    }
    BFS();
    return TS;
}
