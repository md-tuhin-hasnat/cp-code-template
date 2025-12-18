#define SIZE_N 10000000 // 10^7
bool isprime[SIZE_N + 4];
vector<int> prime;
void sieve() {
    for(inti=3;i<=SIZE_N;i+=2)isprime[i]=true;
    isprime[2] = true;
    prime.push_back(2);
    for (ll i = 3; i <= SIZE_N; i += 2) {
        if (isprime[i]) {
            prime.push_back((int)i);
            if ((ll)SIZE_N / i >= i) {
                for (ll j = i * i; j <= SIZE_N; j += 2 * i)
                    isprime[j] = false;
            }
        }
    }
}
//it handle up to 10^14 with current sieve
void prime_factors(ll n) {
    for(int i=0;i<prime.size()&&(ll)prime[i]*prime[i]<=n;i++){
        while (n % prime[i] == 0) {
            cout << prime[i] << " ";
            n /= prime[i];
        }
    }
    if (n > 1) cout << n;
}
int main() {
    sieve();
    prime_factors(100000000000000LL); // 10^14
}