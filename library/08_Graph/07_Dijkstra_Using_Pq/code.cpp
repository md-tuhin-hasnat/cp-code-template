struct Nod{
    int u, dis;
    Nod(int iU, int iDis){
        u = iU;
        dis = iDis;
    }
    bool operator<(const Nod& b) const{
        return dis > b.dis;
    }
};
const int Vertex_N = 101;
const int oo = 1e8+0.5;
int dist[Vertex_N];
int par[Vertex_N];
vector<int>graph[Vertex_N];
vector<int>weight[Vertex_N];
void init(int n){
    for(int i=1;i<=n;i++){
        dist[i] = oo;
        par[i] = -1;
        graph[i].clear();
        weight[i].clear();
    }
}
int dijkstra(int source, int destination){
    priority_queue<Nod>pq;
    dist[source] = 0;
    pq.push(Nod(source, 0));///pq.push({source, 0});
    while(!pq.empty()){
        Nod cur = pq.top();
        pq.pop();

        int u = cur.u;
        int uDist = cur.dis;
        if(dist[u] < uDist) {
            continue;
        }
        for(int i=0;i<graph[u].size();i++){
            int v = graph[u][i];
            int edgeWeight = weight[u][i];
            if(dist[v] > uDist + edgeWeight){
                dist[v] = uDist + edgeWeight;
                par[v] = u;
                pq.push({v, dist[v]});
            }
        }
    }
    return dist[destination];
}
vector<int> getPaht(int source, int destination){
    int v = destination;
    vector<int>path;
    while(source != v){
        path.push_back(v);
        v = par[v];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());
    return path;
}

int main(){
    int V, E, S, D;///S=Point vartex,D=terget vartex distence
    cin>>V>>E>>S>>D;
    init(V);
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(v);
        weight[u].push_back(w);
        ///for undirected graph
        graph[v].push_back(u);
        weight[v].push_back(w);
    }
    int distance = dijkstra(S, D);
    printf("Distace: %d\n", distance);

    vector<int>path = getPaht(S, D);
    printf("Path: ");
    for(auto v: path) cout<<v<<" ";cout<<endl;
}
