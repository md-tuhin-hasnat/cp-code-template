ll dp[10][10][2][2];
ll go(ll pos,ll st,ll ever_sm,ll val,int len,string &s){
    if(pos==len)return val;
    ll &rf=dp[pos][val][ever_sm][st];
    if(rf!=-1)return rf;
    rf=0;
    if(st){
        if(ever_sm){
            for(ll i=0;i<=9;i++){
                rf+=go(pos+1,1,1,val+(i==0),len,s);
            }
        }else{
            for(ll i=0;i<=s[pos]-'0';i++){
                rf+=go(pos+1,1,ever_sm|(i<(s[pos]-'0')),val+(i==0),len,s);
            }
        }
    }else{
        rf+=go(pos+1,0,1,0,len,s);
        if(pos==0){
            for(ll i=1;i<=s[0]-'0';i++){
                rf+=go(pos+1,1 ,ever_sm|(i<(s[pos]-'0')),0,len,s);
            }
        }else{
            for(ll i=1;i<=9;i++){
                rf+=go(pos+1,1 ,1,0,len,s);
            }
        }
    }
    return rf;
}
