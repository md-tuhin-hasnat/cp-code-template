#include<bits/stdc++.h>
using namespace std;

const int no_node=1000;
vector<int>adj[no_node];
int par[no_node];

void init(int V){
    for(int i=0;i<V+5;i++){
        adj[i].clear();
        par[i]=-1;
    }
}

void dfs(int u){
    for(auto v : adj[u]){
        if(v==par[u])continue;
        par[v]=u;
        dfs(v);
    }
}
vector<int>ancestors(int node){
    vector<int>ans;
    while(node != -1){///node no. 1 s parent in -1
        ans.push_back(node);
        node=par[node];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int LCA(int nod1,int nod2){
    vector<int>anc1=ancestors(nod1);
    vector<int>anc2=ancestors(nod2);
    int len=min(anc1.size(),anc2.size());
    int lca=-1;
    for(int i=0;i<len;i++){
        if(anc1[i]==anc2[i]){
            lca=anc1[i];
        }else{
            break;
        }
    }
    return lca;

}
