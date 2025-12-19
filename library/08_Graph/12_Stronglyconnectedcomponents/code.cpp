struct node{
    int idx,st,fin;
};
node Time[Size];
vector<int>adj[Size];
vector<int>radj[Size];
vector<int>component[Size];
int vis[Size],scc[Size],ti,compo_no;
bool com(node a,node b){
    return a.fin>b.fin;
}
bool comidx(node a,node b){
    return a.idx<b.idx;
}
void dfs(int u){
    Time[u].st=ti++;
    vis[u]=1;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(vis[v]==0){
            dfs(v);
        }
    }
    Time[u].fin=ti++;
}
void rdfs(int u,int compo_no){
    vis[u]=1;
    scc[u]=compo_no;///scc[u] is compo_no'th component who is carring nod u
    component[compo_no].push_back(u);
    for(int i=0;i<radj[u].size();i++){
        int v=radj[u][i];
        if(vis[v]==0){
            rdfs(v,compo_no);
        }
    }
}
int main(){
    int V,E,u,v;cin>>V>>E;
    /// SCC works only for directional graph
    for(int i=0;i<=V+5;i++){
        adj[i].clear();
        radj[i].clear();
        component[i].clear();
        vis[i]=0;
    }
    for(int i=1;i<=E;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        radj[v].push_back(u);/// for reverce edges direction
    }
    ti=1;
    for(int i=1;i<=V;i++){/// 1 based graph
        Time[i].idx=i;
        if(vis[i]==0){
            dfs(i);
        }
    }
    // cout<<"[Start time,Finish Time]:\n";
    // for(int i=1;i<=V;i++){
    //     cout<<"Nod "<<i<<" :["<<Time[i].st<<","<<Time[i].fin<<"]\n";
    // }
    memset(vis,0,sizeof vis),compo_no=0;///compo_no = n'th component[1 based]
    sort(&Time[1],&Time[V+1],com);///precedency by finish time
    for(int i=1;i<=V;i++){
        if(vis[Time[i].idx]==0){
            compo_no++;         /// compo_no also compo index which is 1 based
            rdfs(Time[i].idx,compo_no);///dfs traverce for reverse direction
        }
    }
    //sort(&Time[1],&Time[V+1],comidx);
    for(int i=1;i<=compo_no;i++){/// number of component is compo_no
        cout<<"SCC("<<scc[component[i][0]]<<")-> ";///component[i][0] is the 1st node of i'th component
        for(auto v : component[i]){
            cout<<v<<" ";
            //cout<<"-> SCC("<<scc[v]<<") ,";
        }
        cout<<"\n";
    }
    cout<<"\n";

}
