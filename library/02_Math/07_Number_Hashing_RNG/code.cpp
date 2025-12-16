#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    static uint32_t splitmix32(uint32_t x) {//uint64_t
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint32_t x) const {//uint64_t
        static const uint32_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix32(x + FIXED_RANDOM);
    }
}rng;///Random number generator

signed main()
{
    int a=rng(1);
    int b=rng(2);
    int c=rng(3);
    

    cout<<a<<" "<<bitset<32>(a)<<"\n";
    cout<<b<<" "<<bitset<32>(b)<<"\n";
    cout<<c<<" "<<bitset<32>(c)<<"\n";

}
