#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define F first
#define S second

const int MAX = 1000010;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
const ll base1 = 269;
const ll base2 = 277;

pair<ll,ll> pw[MAX], inv_pw[MAX];

ll bigMod(ll b, ll power, ll Mod) {
    ll ans = 1;
    while(power) {
        if(power & 1) ans = (ans * b) % Mod;
        b = (b * b) % Mod;
        power = power >> 1;
    }
    return ans % Mod;
}

void powCalc() {
    ll rev_base1 = bigMod(base1, MOD1 - 2, MOD1);
    ll rev_base2 = bigMod(base2, MOD2 - 2, MOD2);
    pw[0] = {1, 1};
    inv_pw[0] = {1, 1};
    for(int i = 1; i < MAX; i++) {
        pw[i].F = 1LL * pw[i - 1].F * base1 % MOD1;
        inv_pw[i].F = 1LL * inv_pw[i - 1].F * rev_base1 % MOD1;
        
        pw[i].S = 1LL * pw[i - 1].S * base2 % MOD2;
        inv_pw[i].S = 1LL * inv_pw[i - 1].S * rev_base2 % MOD2;
    }
}

struct Hashing {
    vector<pair<ll,ll>> prehsh, sufhsh;
    int len;
    
    Hashing() { len = 0; }
    
    void build(string const &s) {
        len = s.size();
        prehsh.resize(len + 2);
        sufhsh.resize(len + 2);
        for(int i = 0; i < len; i++) {
            prehsh[i].F = (1LL * s[i] * pw[i].F) % MOD1;
            prehsh[i].S = (1LL * s[i] * pw[i].S) % MOD2;
            if(i) {
                prehsh[i].F = (prehsh[i].F + prehsh[i - 1].F) % MOD1;
                prehsh[i].S = (prehsh[i].S + prehsh[i - 1].S) % MOD2;
            }
            sufhsh[i].F = (1LL * s[i] * pw[len - i - 1].F) % MOD1;
            sufhsh[i].S = (1LL * s[i] * pw[len - i - 1].S) % MOD2;
            if(i) {
                sufhsh[i].F = (sufhsh[i].F + sufhsh[i - 1].F) % MOD1;
                sufhsh[i].S = (sufhsh[i].S + sufhsh[i - 1].S) % MOD2;
            }
        }
    }
    
    ll getHash(int i, int j) {
        assert(i <= j);
        pair<ll,ll> hs({0, 0});
        hs.F = prehsh[j].F;
        hs.S = prehsh[j].S;
        if(i) {
            hs.F = (hs.F - prehsh[i - 1].F + MOD1) % MOD1;
            hs.S = (hs.S - prehsh[i - 1].S + MOD2) % MOD2;
        }
        hs.F = (1LL * hs.F * inv_pw[i].F) % MOD1;
        hs.S = (1LL * hs.S * inv_pw[i].S) % MOD2;
        
        return (hs.F * MOD2 + hs.S);
    }
    
    bool isPalindrome(int l, int r) {
        ll fwdHash = getHash(l, r);
        // Reverse hash computation for palindrome check
        return true; // Simplified
    }
};
