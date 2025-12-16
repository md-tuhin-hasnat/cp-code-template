#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL bigMod(LL b, LL power, LL mod) {
    LL ans = 1;
    while(power) {
        if(power & 1) ans = (ans * b) % mod;
        b = (b * b) % mod;
        power = power >> 1;
    }
    return ans % mod;
}
