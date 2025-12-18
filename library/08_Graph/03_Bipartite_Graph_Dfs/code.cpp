vector<int>adj[SIZE];
int color[SIZE],V,E,u,v;
bool DFS(int u,int col){
    color[u]=col;
    for(auto v : adj[u]){
        if(color[v]==-1){
            if(DFS(v,!col)==false)/// color[v]= reverse color[u]
                return false;
        }
        else if(color[v]==col){
            return false;
        }
    }
    return true;
}
signed main(){
    cin>>V>>E;
    for(int i=0;i<V+5;i++){
        color[i]=-1;
        adj[i].clear();
    }
    for(int i=0;i<E;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int flg=1;
    for(int i=1;i<=V;i++){///1 based
        if(color[i]==-1){
            if(DFS(i,0)==false){
                flg=0;
                break;
            }
        }
    }
    ///if graph has a cycle which is contain odd number of nodes
    ///in that case graph is not  Bipartite Graph
    if(flg){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
}
