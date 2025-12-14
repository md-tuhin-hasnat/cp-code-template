MOD = 10**9 + 7

def factorial(n, mod=MOD):
    """Calculate factorial modulo mod"""
    fact = [1] * (n + 1)
    for i in range(1, n + 1):
        fact[i] = (fact[i-1] * i) % mod
    return fact

def modinv(a, mod=MOD):
    """Calculate modular inverse using Fermat's Little Theorem"""
    return pow(a, mod - 2, mod)

def nCr(n, r, mod=MOD):
    """Calculate nCr modulo mod"""
    if r > n or r < 0:
        return 0
    
    fact = factorial(n, mod)
    return (fact[n] * modinv(fact[r], mod) % mod * 
            modinv(fact[n-r], mod)) % mod
