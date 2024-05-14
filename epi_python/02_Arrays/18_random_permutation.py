from typing import List
import random

def random_sampling(k: int, A: List[int]) -> None:
    for i in range(k):
        r = random.randint(i, len(A) - 1)
        A[i], A[r] = A[r], A[i]

def compute_random_permutation(n: int) -> List[int]:
    permutation = list(range(n))
    random_sampling(n, permutation)
    return permutation

if __name__ == '__main__':
    n = 5
    perm = compute_random_permutation(n)
    print(*perm, end="\n")