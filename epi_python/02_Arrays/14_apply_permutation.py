from typing import List

def apply_permutation(perm: List[int], A: List[int]) -> None:
    for i in range(len(A)):
        while perm[i] != i:
            A[perm[i]], A[i] = A[i], A[perm[i]]
            perm[perm[i]], perm[i] = perm[i], perm[perm[i]]

if __name__ == '__main__':
    A = [1, 2, 3, 4]
    perm = [2, 0, 1, 3]
    apply_permutation(perm, A)
    for i in A:
        print(i)