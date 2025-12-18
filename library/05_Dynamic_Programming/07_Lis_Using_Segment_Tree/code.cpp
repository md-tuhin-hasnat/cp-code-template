
void solve(){
    cin>>n;
    int ar[n+2];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }

    // segmentree not working above 1e6 // needs to compress values 
    // coordinate compression, now all a[i] are 1 <= a[i] <= n which is cute
    /**
        set<int>s;
        for(int i=0;i<n;i++)s.insert(ar[i]);
        int id=0;
        map<int,int>mp;
        for(auto it : s)mp[it]=++id;
        for(int i=0;i<n;i++)ar[i]=mp[ar[i]];
    */
    int max_value=n;// after compression max value will be n or id
    // segment tree on value
    // MAX Segment Tree
    st.build(1,1,max_value); 
    vector<int>dp(n+2,1);
    int mx=1;
    for(int i=0;i<n;i++){
        // for(int j=0;j<i;j++){
        //     if(ar[j]<ar[i]){
        //         dp[i]=max(dp[i],1+dp[j]);
        //     }
        // }
        // mx=max(dp[i],mx);
        dp[i]=max(dp[i],st.query(1,1,max_value,1,ar[i]-1)+1);// MAX Segment Tree
        st.update(1,1,max_value,ar[i],dp[i]);// MAX Segment Tree update
        mx=max(mx,dp[i]);
    }
    cout<<mx<<"\n";

}