string s;int q;
int ispal[5010][5010];
int IsPallindrome(int l , int r) {
    if(l>r)return 1;
    if(ispal[l][r]!=-1)return ispal[l][r];
    return ispal[l][r]= s[l]==s[r] & IsPallindrome(l+1,r-1);
}
int dp[5010][5010];
int num_of_palin(int l,int r){
    if(l>r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    return dp[l][r]=IsPallindrome(l,r)+
        num_of_palin(l+1,r)+num_of_palin(l,r-1)-num_of_palin(l+1,r-1);
}
int main() {
    cin>>s>>q;
    memset(dp,-1,sizeof dp);
    memset(ispal,-1,sizeof ispal);
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        cout<<num_of_palin(l,r)<<"\n";
    }
}