#include <bits/stdc++.h>
using namespace std;

int ar[1005][1005], px[1005][1005];

void build2DPrefixSum(int r, int c) {
    for(int i = 0; i <= r; i++) px[i][0] = 0;
    for(int j = 0; j <= c; j++) px[0][j] = 0;
    
    px[1][1] = ar[1][1];
    for(int i = 2; i <= r; i++) {
        px[i][1] = px[i - 1][1] + ar[i][1];
    }
    for(int j = 2; j <= c; j++) {
        px[1][j] = px[1][j - 1] + ar[1][j];
    }
    
    for(int i = 2; i <= r; i++) {
        for(int j = 2; j <= c; j++) {
            px[i][j] = px[i - 1][j] + px[i][j - 1] + ar[i][j] - px[i - 1][j - 1];
        }
    }
}

int rangeSum2D(int i1, int j1, int i2, int j2) {
    return px[i2][j2] - px[i2][j1 - 1] - px[i1 - 1][j2] + px[i1 - 1][j1 - 1];
}
