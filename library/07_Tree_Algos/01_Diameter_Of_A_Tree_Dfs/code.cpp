int depth[Size];
vector<int>graph[Size];
int max_depth;
int max_depth_node;
void init(int V){
    for(int i=0;i<V+5;i++){
        graph[i].clear();depth[i]=0;
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
int main(){
    int V,u,v;cin>>V;
    init(V);
    int E=V-1;
    for(int i=0;i<E;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    max_depth_node=dfs(1);///one based
    memset(depth,0,sizeof depth);
    max_depth=0;
    max_depth_node=dfs(max_depth_node);
    cout<<"Diameter of this Tree = "<<depth[max_depth_node]<<"\n";

}

