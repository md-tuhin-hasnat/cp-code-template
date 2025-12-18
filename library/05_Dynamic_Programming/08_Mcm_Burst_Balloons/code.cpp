int go(int i,int j){
    if(i>j)return 0;
    int &rf=dp[i][j];
    if(rf!=-1)return rf;
    rf=-9999999;
    for(int idx=i;idx<=j;idx++){
        rf=max(rf,ar[i-1]*ar[idx]*ar[j+1]+go(i,idx-1)+go(idx+1,j));
    }
    return rf;
}