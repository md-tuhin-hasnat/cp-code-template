ll mul(ll a, ll b, ll mod) { // a * b % mod
  return __int128(a) * b % mod;
}
ll power(ll a, ll b, ll mod) { // a^b % mod
  ll ans = 1 % mod;
  while (b) {
    if (b & 1) ans = mul(ans, a, mod);
    a = mul(a, a, mod);
    b >>= 1;
  }
  return ans;
}
ll inverse(ll a, ll mod) { // (1 / a) % mod
  return power(a, mod - 2, mod);
}