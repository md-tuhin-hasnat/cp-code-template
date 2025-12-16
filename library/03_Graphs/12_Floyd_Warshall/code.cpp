#include <bits/stdc++.h>
using namespace std;

const int oo = 1e8;
const int Size = 505;
int dis[Size][Size];

void floydWarshall(int N) {
    for(int via = 1; via <= N; via++) {
        for(int u = 1; u <= N; u++) {
            for(int v = 1; v <= N; v++) {
                dis[u][v] = min(dis[u][v], dis[u][via] + dis[via][v]);
            }
        }
    }
}

void init(int N) {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            dis[i][j] = oo;
            if(i == j) dis[i][j] = 0;
        }
    }
}
