#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
bool visited[100005];

void dfs(int u) {
    visited[u] = true;
    // Process node u
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

// Iterative DFS
void dfs_iterative(int start) {
    stack<int> st;
    st.push(start);
    
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        // Process node u
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                st.push(v);
            }
        }
    }
}
