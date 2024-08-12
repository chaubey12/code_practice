from typing import List

def find_first_missing_positive(A: List[int]) -> int:
    for i in range(len(A)):
        while 1 <= A[i] <= len(A) and A[i] != A[A[i] - 1]:
            A[A[i] - 1], A[i] = A[i], A[A[i] - 1]
    return next((i + 1 for i, a in enumerate(A) if a != i + 1), len(A) + 1)

if __name__ == '__main__':
    A = [3, 5, 4, -1, 5, 1, -1]
    print(find_first_missing_positive(A))