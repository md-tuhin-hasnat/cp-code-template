#include <bits/stdc++.h>
using namespace std;

// Extended Euclidean Algorithm
long long extgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// Modular inverse
long long modinv(long long a, long long m) {
    long long x, y;
    long long gcd = extgcd(a, m, x, y);
    if (gcd != 1) return -1;  // No inverse exists
    return (x % m + m) % m;
}

// Fast exponentiation
long long power(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
