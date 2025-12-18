struct Edge{
    int u,v,w;
};
vector<Edge>edgeList;
int dist[V_SZ];
int par[V_SZ];
int V,E,Source;
const int oo = (1<<25);

void init(){
    for(int i =1;i<=V;i++)
    {
        dist[i] = oo;
        par[i] = -1;
    }
    edgeList.clear();
}

bool bellmanFord_IsNegCyc(int Source){
    dist[s] = 0;
    bool isUpdated;
    /// bellmanford needs meximum V-1 itaration for update all
    ///nodes minimum distance from source .but why there
    /// is V iteration , becouse if its update a nodes distance
    /// after V-1 iteration that means it have nagative cycle
    for(int i=1;i<=V;i++)
    {
        isUpdated = false;

        for(auto edg: edgeList){
            if(dist[edg.v] > dist[edg.u] + edg.w){
                dist[edg.v] = dist[edg.u] + edg.w;
                par[edg.v] = edg.u;
                isUpdated = true;/// if its update V'th itaration
                                /// thats means it has nagative cycle
            }
        }
    }
    return isUpdated;
}
