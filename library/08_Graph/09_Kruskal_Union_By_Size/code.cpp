struct Edge{
    int u,v,w;
    Edge(int ui,int vi,int wi){
        u=ui;v=vi;w=wi;
    }
};
vector<Edge>edgeList;
int parant[sz];
int compoSize[sz];
void disjoint(int V){
    edgeList.clear();
    for(int i=0;i<=V+3;i++){
        parant[i]=i;///call by make func in DSU
        compoSize[i]=1;
    }
}
/// finding root node of this component and
/// make root node is parant of the all nodes of this component
int FindRootParant(int node){
    if(node == parant[node])
        return node;
    return parant[node]=FindRootParant(parant[node]);
}
/// joining two components
void join_components(int u,int v){///union/makelink  u nodes component
                                /// to v nodes component and
                                 /// make them as a same component

    int u_parant=FindRootParant(u); /// finding u 's root node
    int v_parant=FindRootParant(v); /// finding v 's root node

    if(u_parant==v_parant)///both r alrady joined
        return ;
    if(compoSize[u_parant]>compoSize[v_parant]){
        parant[v_parant]=u_parant;
        compoSize[u_parant]+=compoSize[v_parant];
    }
    else{
        parant[v_parant]=u_parant;
        compoSize[v_parant]+=compoSize[u_parant];
    }
}
bool com_by_waight(Edge a,Edge b){
    return a.w<b.w;
}
int kruskal(){
    int cost=0;
    sort(edgeList.begin(),edgeList.end(),com_by_waight);

    for(int i=0;i<edgeList.size();i++){
        ///if two vertex or groups root parent r same
        ///then it will be creat a cycle
        ///Then we won't add them
        ///else ↓
        if(FindRootParant(edgeList[i].u) != FindRootParant(edgeList[i].v)){
            join_components(edgeList[i].u , edgeList[i].v);
            cost+=edgeList[i].w;
            ///connecting edges
            cout<<edgeList[i].u<<"<->"<<edgeList[i].v<<" = "<<edgeList[i].w;el;
        }
    }
    return cost;
}

int main(){
    int V,E;cin>>V>>E;
    disjoint(V);///init
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edgeList.push_back({u,v,w});
    }
    int MST_Cost = kruskal();
    cout<<"MST COST = "<<MST_Cost;el;
    
}