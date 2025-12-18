string dp[105][105];
bool vis[105][105];
string  lcs(int i,int j){
    if(i==n || j==m)return "";
    if(vis[i][j])return dp[i][j];

    vis[i][j]=true;
    string ans="";
    if(txt[i]==pat[j]){
        ans=txt[i]+lcs(i+1,j+1);
    }else{
        string a=lcs(i+1,j);
        string b=lcs(i,j+1);
        if(a.size()>b.size()){
            ans=a;
        }else if(a.size()<b.size()){
            ans=b;
        }else{
            ans=min(a,b);
        }
    }
    dp[i][j]=ans;
    return dp[i][j];
}
