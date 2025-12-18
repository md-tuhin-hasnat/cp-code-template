typedef struct{int x,y;}co;
int dis[1006][1006],n;
int dp[1<<17][17];
int N,k;
co ic[20];
void BFS(){
    queue<co>q;
    int r,c,ur,uc,
    dr[] = {2,2,1,1,-1,-1,-2,-2},
    dc[] = {1,-1,2,-2,2,-2,1,-1};
    memset(dis,-1,sizeof(dis));
    dis[2][2] = 0;
    q.push({2,2});

    while(!q.empty())
    {
        ur = q.front().x; 
        uc = q.front().y; 
        q.pop();
        for(int i=0;i<8;i++){
            r = ur+ dr[i];  c = uc+ dc[i];
            if(r>=0 && c>=0 && r<=1002 && c<=1002 && dis[r][c]==-1){
                q.push({r,c});
                dis[r][c] = dis[ur][uc]+1;
            }
        }
    }
}
int DIS(co a,co b){
    if(
        (a.x==1 && a.y==1 && b.x==2 && b.y==2) ||
        (a.x==2 && a.y==2 && b.x==1 && b.y==1) ||
        (a.x==n-1 && a.y==n-1 && b.x==n && b.y==n) ||
        (a.x==n && a.y==n && b.x==n-1 && b.y==n-1) ||
        (a.x==1 && a.y==n && b.x==2 && b.y==n-1) ||
        (a.x==2 && a.y==n-1 && b.x==1 && b.y==n) ||
        (a.x==n && a.y==1 && b.x==n-1 && b.y==2) ||
        (a.x==n-1 && a.y==2 && b.x==n && b.y==1)
    )
    return 4;
    return dis[abs(a.x-b.x)+2][abs(a.y-b.y)+2];
}
int go(int msk,int cur){
    if(msk== ((1<<k)-1))return DIS(ic[cur],ic[0]); 
    int &rf=dp[msk][cur];
    if(rf!=-1)return rf;
    rf=1<<30;
    for(int i=0;i<k;i++){
        if((msk&(1<<i))==0){
            rf=min(rf,go((msk|(1<<i)),i)+DIS(ic[cur],ic[i]));
        }
    }
    return rf;
}
int main(){
    co s,a,b;int t,ks=0;
    BFS();//pre
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof dp);
        cin>>n>>k;
        for(int i=0;i<k;i++){
            cin>>ic[i].x>>ic[i].y;
        }
        cout<<go(0,0)<<"\n";
    }
}
