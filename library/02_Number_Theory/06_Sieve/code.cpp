///Nlog(N)
const int N = 1e7 + 9;
bitset<N> not_prime;
vector<int> primes;
void sieve(){
    not_prime[1] = true;
    for (int i = 2; i * i <= N; i++) {
        if (!not_prime[i]) {///prime
          for (int j = i * i; j <= N; j += i) {
            not_prime[j] = true;
          }
        }
    }
    for (int i = 2; i <= N; i++) {
        if (!not_prime[i]) { /// prime
          primes.push_back(i);
        }
    }
}
