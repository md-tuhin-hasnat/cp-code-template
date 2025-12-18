vector<vector<ll>> matMulti(vector<vector<ll>>&a, vector<vector<ll>>&b, ll Mod){
    int r = a.size();
    int c = b[0].size();
    vector<vector<ll>> ans(r, vector<ll>(c, 0));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            for(int k = 0; k < a[0].size(); k++) {
                ans[i][j]=((ans[i][j]+(a[i][k]*b[k][j])%Mod)%Mod+Mod)%Mod;
            }
        }
    }
    return ans;
}
vector<vector<ll>> matExpo(vector<vector<ll>>& b, ll pw, ll Mod){
    int r = b.size();
    vector<vector<ll>> ans(r, vector<ll>(r, 0)); 
    for(int i = 0; i < r; ++i) {
        ans[i][i] = 1;
    }
    while(pw) {
        if(pw & 1) {
            ans = matMulti(ans, b, Mod);
        }
        b = matMulti(b, b, Mod);
        pw >>= 1;
    }
    return ans;
}
