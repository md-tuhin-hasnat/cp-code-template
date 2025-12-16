#include<bits/stdc++.h>
using namespace std;

///Complexity: O(NlgN,lgN)
const int Size = 100010;

int E,V;
int LVL[Size];
int par[Size];
int A[Size][20];
vector<int>adj[Size];

/// finding nodes tree level and parent
void leveling_dfs(int u){
    for(auto v : adj[u]){
        if(v==par[u])continue;
        LVL[v]=LVL[u]+1;
        par[v]=u;
        leveling_dfs(v);
    }
}

void Sparse_Table()
{
    // creating sparse table
    for(int p=0;p<=log2(V)+1;p++)
    {
        for(int i=1;i<=V;i++)
        {
            if(p==0)
                A[i][p] = par[i];///2^p = 2^0 = 1'th parent
            else
                A[i][p] = A[A[i][p-1]][p-1];///  A[i][p] = i'th nodes 2^p'th parant
        }
    }
}

int LCA(int u,int v)
{
    if(LVL[u]>LVL[v])
        swap(u,v);
    //Bring u and v in same level
    for(int i=log2(V)+1;i>=0;i--){
        int x = A[v][i];
        if(LVL[u]==LVL[x]){
            v=x;
            break;
        }
        if(LVL[u]<LVL[x])
            v = x;
    }
    if(u==v)return u;

    for(int i=log2(V)+1;i>=0;i--)
    {
        if(A[u][i] != -1 && A[u][i] != A[v][i])
        {
            u = A[u][i];
            v = A[v][i];
        }
    }
    return par[u];
}
int distance(int u,int v){
    int an=LCA(u,v);
    return LVL[u]+LVL[v]-2*LVL[an];
}
void build_LCA(int source){
    LVL[source]=1,par[source]=source;
    leveling_dfs(source);
    Sparse_Table();
}
