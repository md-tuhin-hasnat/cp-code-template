#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int spf[N];

void spfPreCalc() {
    for(int i = 2; i <= N; i++) {
        spf[i] = i;
    }
    for(int div = 2; div <= N; div++) {
        for(int i = div; i <= N; i += div) {
            spf[i] = min(spf[i], div);
        }
    }
}

vector<int> primeFactors(int n) {
    vector<int> factors;
    while(n > 1) {
        factors.push_back(spf[n]);
        n /= spf[n];
    }
    return factors;
}
