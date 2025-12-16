#include <bits/stdc++.h>
using namespace std;

int ar[100005], pre[100005];

void buildPrefixSum(int n) {
    pre[0] = 0;
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + ar[i];
    }
}

int rangeSum(int l, int r) {
    return pre[r] - pre[l - 1];
}
