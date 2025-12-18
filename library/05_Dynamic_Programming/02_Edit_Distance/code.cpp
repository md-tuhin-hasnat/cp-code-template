int EditDistance(int i,int j){
    if(i<0)return j+1;
    if(j<0)return i+1;

    if(memo[i][j]!=-1)return memo[i][j];

    if(s1[i]==s2[j])
        return memo[i][j]= EditDistance(i-1,j-1);

    /// any move cost 1
    int Insert = 1 + EditDistance(i,j-1);
    int Delete = 1 + EditDistance(i-1,j);
    int Remove = 1 + EditDistance(i-1,j-1);
    return memo[i][j]=min({Insert,Delete,Remove});
}
i