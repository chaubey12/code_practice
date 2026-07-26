from typing import Dict

cache : Dict[int, int] = {}

def fibonacci(n: int) -> int:
    if n <= 1:
        return n
    elif n not in cache:
        cache[n] = fibonacci(n-1) + fibonacci(n-2)
    return cache[n]
