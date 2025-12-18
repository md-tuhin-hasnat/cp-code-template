int lcs(int t,int p){
    if(t==n || p==m){
        return 0;
    }
    if(memo[t][p]!=-1)return memo[t][p];
    if(txt[t]==pat[p]){
        memo[t][p]=1+lcs(t+1,p+1);
    }
    else{
        memo[t][p]=max(lcs(t+1,p),lcs(t,p+1));
    }
    return memo[t][p];
}
void path(int t,int p){
    if(t==n || p==m)return;
    if(txt[t]==pat[p]){
        ans+=txt[t];
        path(t+1,p+1);
    }
    else if(memo[t+1][p]>memo[t][p+1]){
        path(t+1,p);
    }
    else {
        path(t,p+1);
    }
}
