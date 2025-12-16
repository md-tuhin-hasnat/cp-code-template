#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1000000;
const ll MOD = 1e9 + 7;

ll fact[N + 10];
ll inv_fact[N + 10];

ll bigMod(ll base, ll power, ll mod = 1e9 + 7) {
    ll ans = 1;
    while(power) {
        if(power & 1) ans = (ans * base) % mod;
        base = (base * base) % mod;
        power = power >> 1;
    }
    return ans;
}

ll inverse(ll base, ll mod = 1e9 + 7) {
    return bigMod(base % mod, mod - 2, mod) % mod;
}

void preCalc() {
    fact[0] = 1;
    for (ll i = 1; i <= N; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    
    inv_fact[N] = inverse(fact[N]);
    for (ll i = N - 1; i >= 0; i--)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
}

ll nCr(ll n, ll r) {
    if (r > n || r < 0) return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

ll nPr(ll n, ll r) {
    if (r > n || r < 0) return 0;
    return fact[n] * inv_fact[n - r] % MOD;
}
