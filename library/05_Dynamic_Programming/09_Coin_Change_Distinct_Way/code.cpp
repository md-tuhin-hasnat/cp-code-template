memset(dp,0,sizeof dp);
dp[0]=1;
for(int i=0;i<n;i++){
    for(int j=0;j<=s;j++){
        if(j-c[i]>=0){
            dp[j]=dp[j]+dp[j-c[i]]%MOD;
        }
    }
}
cout<<dp[s]%MOD<<endl;
