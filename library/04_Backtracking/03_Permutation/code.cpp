int n,r;
int color[S],sto[S];
void go(int depth){
    if(depth==r){
        for(int i=0;i<r;i++){
            printf("%d ",sto[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        if(color[i]==false){
            color[i]=true;
            sto[depth]=i;
            go(depth+1);
            color[i]=false;
        }
    }
}
int main(){
    while(cin>>n>>r){
        memset(color, false, sizeof color);
        go(0);
    }
}




