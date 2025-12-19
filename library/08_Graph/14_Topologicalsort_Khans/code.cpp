const int Size=105;
vector<int>adj[Size];
vector<int>TS;///Topological Sort
int indegree[Size],V,E;
queue<int>Q;
void init(){
    for(int i=0;i<V+5;i++){
        indegree[i]=0;
        adj[i].clear();
    }
    TS.clear();
}
void topo_BFS(){
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(auto v : adj[u]){
            --indegree[v];
            if(indegree[v]==0){
                TS.emplace_back(v);
                Q.push(v);
            }
        }
    }
}
int main(){
    cin>>V>>E;
    init();int u,v;
    for(int i=0;i<E;i++){
        cin>>u>>v;
        adj[u].emplace_back(v);
        ++indegree[v];
    }
    for(int i=1;i<=V;i++){///1 based
        if(indegree[i]==0){
            TS.emplace_back(i);
            Q.push(i);
        }
    }
    topo_BFS();
    if(TS.size()!=V){
        cout<<"CycleExist\n";
    }
    for(auto it : TS){
        cout<<it<<" ";
    }
    cout<<"\n";
}
