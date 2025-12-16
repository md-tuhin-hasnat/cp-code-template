#include<bits/stdc++.h>
using namespace std;
const int Size=1000;

int depth[Size];
vector<int>graph[Size];
int max_depth;
int max_depth_node;
void init(int V){
    for(int i=0;i<V+5;i++){
        graph[i].clear();
        depth[i]=0;
    }
    max_depth=0;
}
int dfs(int u,int par=-1){
    if(depth[u]>max_depth){
        max_depth=depth[u];
        max_depth_node=u;
    }
    for(auto v : graph[u]){
        if(v==par)continue;
        depth[v]=depth[u]+1;
        dfs(v,u);
    }
    return max_depth_node;
}
