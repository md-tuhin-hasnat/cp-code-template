#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 100007;
int ar[MAX_N];

struct LazyTree {
    vector<int> tre, lazy;
    
    LazyTree(int sz) {
        tre.assign((sz * 4) + 10, 0);
        lazy.assign((sz * 4) + 10, 0);
    }
    
    inline void lazyUpdate(int nod, int sl, int sr) {
        if(lazy[nod] == 0) return;
        tre[nod] += lazy[nod] * (sr - sl + 1);
        if(sl != sr) {
            int left_child = 2 * nod, right_child = 2 * nod + 1;
            lazy[left_child] += lazy[nod];
            lazy[right_child] += lazy[nod];
        }
        lazy[nod] = 0;
    }
    
    void build(int nod, int sl, int sr) {
        lazy[nod] = 0;
        if(sl == sr) {
            tre[nod] = ar[sr];
            return;
        }
        int mid = (sl + sr) / 2;
        int left_child = 2 * nod, right_child = 2 * nod + 1;
        
        build(left_child, sl, mid);
        build(right_child, mid + 1, sr);
        
        tre[nod] = tre[left_child] + tre[right_child];
    }
    
    ll query(int nod, int sl, int sr, int ql, int qr) {
        lazyUpdate(nod, sl, sr);
        if(ql <= sl && sr <= qr) {
            return tre[nod];
        }
        if(qr < sl || sr < ql) return 0;
        int mid = (sl + sr) / 2;
        int left_child = 2 * nod, right_child = 2 * nod + 1;
        
        return query(left_child, sl, mid, ql, qr) + query(right_child, mid + 1, sr, ql, qr);
    }
    
    void update(int nod, int sl, int sr, int ql, int qr, ll val) {
        lazyUpdate(nod, sl, sr);
        if(ql <= sl && sr <= qr) {
            lazy[nod] += val;
            lazyUpdate(nod, sl, sr);
            return;
        }
        if(qr < sl || sr < ql) return;
        
        int mid = (sl + sr) / 2;
        int left_child = 2 * nod, right_child = 2 * nod + 1;
        
        update(left_child, sl, mid, ql, qr, val);
        update(right_child, mid + 1, sr, ql, qr, val);
        
        tre[nod] = tre[left_child] + tre[right_child];
    }
};
