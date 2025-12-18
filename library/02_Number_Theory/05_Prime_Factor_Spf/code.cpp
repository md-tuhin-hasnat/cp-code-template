int spf[N];///smallest prime factor
void spf_pre_clc(){///nlog(log(n))
    for(int i=2;i<=N;i++){
        spf[i]=i;
    }
    for(int div=2;div<=N;div++){
        for(int i=div;i<=N;i+=div){
            spf[i]=min(spf[i],div);
        }
    }
}
void prime_factors(int n){///log(n)
    while(n>1){
        cout<<spf[n]<<" ";
        n/=spf[n];
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    spf_pre_clc();
    int n;
    cin>>n;
    prime_factors(n);
}