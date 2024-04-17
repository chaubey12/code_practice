from typing import List
from random import randint

def random_sampling(k: int, A: List[int])->None:
    for i in range(k):
        r = randint(i, len(A))
        A[i], A[r] = A[r], A[i]

if __name__ == '__main__':
    for _ in range(10):
        A = [1,2,3,4,5,6,7]
        k = 3
        random_sampling(k, A)
        result = A[:k]
        print(*result, end=" ")


