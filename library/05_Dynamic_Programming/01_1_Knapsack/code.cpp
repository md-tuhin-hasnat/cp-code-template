int knapSack(int i, int sto) {
   if (sto < 0)return INT_MIN;
   if (i < 0 || sto == 0)return 0;

   if(memo[i][sto]!=-1)return memo[i][sto];

   int in = val[i]+knapSack(i-1, sto-wt[i]);
   int ex = knapSack(i-1, sto);
   return memo[i][sto]=max(in, ex);
}
void path(int i,int sto){
    if(sto<0)return;
    if(i<0 || sto==0) return;
    int in=memo[i-1][sto-wt[i]]+val[i];
    int ex=memo[i-1][sto];
    if(in>ex){
        v.push_back(val[i]);
        path(i-1,sto-wt[i]);
    }
    else{
        path(i-1,sto);
    }
}

