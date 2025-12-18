const int nodes=105;
int timer;
int vis[nodes],tin[nodes],tlow[nodes];
vector<int>adj[nodes];
vector<pair<int,int>>bridge;
void bridge_dfs(int node,int parent){
    vis[node]=1;
    tin[node]=tlow[node]=timer;
    timer++;
    for(auto v : adj[node]){
        if(v==parent)continue;
        if(vis[v]==0){
            bridge_dfs(v,node);
            tlow[node]=min(tlow[v],tlow[node]);
            if(tlow[v]>tin[node]){
                bridge.push_back({node,v});
            }
        }else{
            tlow[node]=min(tin[v],tlow[node]);
        }
    }
}
void init(int V){
    for(int i=0;i<V+5;i++){
        vis[i]=0;
        adj[i].clear();
    }
    timer=1;bridge.clear();
}

int main(){
    ///zero based;
    int V,E;
    cin>>V>>E
    init(V);
    for(int i=0;i<E;i++){
       int u,v;cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);///underected graph
    }
    for(int i=0;i<V;i++){///zero based;
        if(vis[i]==0)bridge_dfs(i,-1);
    }
    for(auto it : bridge){
        cout<<it.first<<"->"<<it.second<<"\n";
    }
    if(bridge.size()==0)cout<<"No Bridges\n";
    cout<<"\n";
    return 0;
}
