from typing import List

def generate_primes(n: int)->List[int]:
    primes = []
    is_prime = [False, False] + [True]*(n-1)
    for p in range(2, n+1):
        if is_prime[p]:
            primes.append(p)
            for i in range(p*2, n+1, p):
                is_prime[i] = False
    return primes

if __name__ == '__main__':
    primes = generate_primes(10)
    for prime in primes:
        print(prime)