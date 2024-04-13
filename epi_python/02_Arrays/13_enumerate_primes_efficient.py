from typing import List

def generate_primes(n: int)->List[int]:
    if n < 2:
        return []
    size = (n-3) // 2 + 1
    primes = [2]
    is_prime = [True]*size
    for i in range(size):
        if is_prime[i]:
            p = i*2 + 3
            primes.append(p)
            for j in range(2 * i**2 + 6*i + 3, size, p):
                is_prime[j] = False
    return primes

if __name__ == '__main__':
    primes = generate_primes(100)
    for prime in primes:
        print(prime)