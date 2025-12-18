template <typename T>
T INV(T base,T mod=1e9+7){//defult mod=1e9+7
    return BIGMOD(base%mod,mod-2,mod)%mod;///base^-1
}
long long  fact[N+10];
long long inv_fact[N+10];
void pre() {
    fact[0] = 1;
    for (long long i = 1; i <= N; i++)
        fact[i] = (fact[i - 1]* i)%MOD;
    
    inv_fact[N] = INV(fact[N]);
    for (long long i=N-1;i>=0;i--)
        inv_fact[i] = (inv_fact[i + 1]*(i+1))%MOD;
    
}
long long nCr(long long n, long long r) {
    if (r > n || r < 0) return 0;
    return fact[n] * inv_fact[r]%MOD*inv_fact[n-r]%MOD;
}
long long nPr(long long n, long long r) {
    if (r > n || r < 0) return 0;
    return fact[n] * inv_fact[n-r]%MOD;
}
signed main(){
    pre();
    int n,r;
    cin>>n>>r;
    cout<<nCr(n,r)<<" "<<nPr(n,r)<<"\n";
}

other way NCR
long long ncr(int n, int r){
    int res = 1;
    for (int i=0; i<r; i++){
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}
