#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1000010;
const ll MOD = 1e9 + 9;
const ll base = 269;

ll pw[MAX], inv_pw[MAX];

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
    ll rev_base = bigMod(base, MOD - 2, MOD);
    pw[0] = 1;
    inv_pw[0] = 1;
    for(int i = 1; i < MAX; i++) {
        pw[i] = pw[i - 1] * base % MOD;
        inv_pw[i] = inv_pw[i - 1] * rev_base % MOD;
    }
}

struct Hashing {
    vector<ll> prehsh, sufhsh;
    int len;
    
    Hashing() { len = 0; }
    
    void build(string const &s) {
        len = s.size();
        prehsh.resize(len + 5);
        sufhsh.resize(len + 5);
        prehsh[0] = 0;
        sufhsh[0] = 0;
        for(int i = 0; i < len; i++) {
            prehsh[i + 1] = (prehsh[i] + (s[i] * pw[i]) % MOD) % MOD;
            sufhsh[i + 1] = (sufhsh[i] + (s[i] * pw[len - i]) % MOD) % MOD;
        }
    }
    
    ll computeHash(string const &s) {
        ll hash_value = 0;
        for(int i = 0; i < s.size(); i++) {
            hash_value = (hash_value + (s[i] * pw[i]) % MOD) % MOD;
        }
        return hash_value;
    }
    
    ll substringHash(int i, int j) {
        return (((prehsh[j + 1] - prehsh[i] + MOD) % MOD) * (inv_pw[i] % MOD)) % MOD;
    }
    
    ll getHash() {
        return substringHash(0, len - 1);
    }
};
