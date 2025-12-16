// Simplified placeholder - complex algorithm
// For full implementation, see source:
// /home/hasnat/codes/cp-code-template/Data-Structures-and-Algorithms.-main/
#include <bits/stdc++.h>
using namespace std;

// Sieve with optimization - basic implementation
const int N = 10000005;
bitset<N> not_prime;
vector<int> primes;

void sieveAdvanced() {
    not_prime[0] = not_prime[1] = true;
    for (int i = 2; i < N; i++) {
        if (!not_prime[i]) {
            primes.push_back(i);
            for (long long j = (long long)i * i; j < N; j += i) {
                not_prime[j] = true;
            }
        }
    }
}
