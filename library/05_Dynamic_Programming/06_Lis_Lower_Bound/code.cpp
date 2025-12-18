int LIS(vector<int>&a){
    vector<int>v;
    int ans=0;
    for(auto x : a){
        auto it =lower_bound(v.begin(),v.end(),x);
        ans=max(ans,(int)(it-v.begin()+1));
        if(it==v.end()){
            v.push_back(x);
        }else{
            *it=x;
        }
    }
    return ans;
}
