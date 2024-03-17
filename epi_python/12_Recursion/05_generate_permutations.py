from typing import List

def permutations(A: List[int])->List[List[int]]:
    def directed_permutation(i):
        if i == len(A) - 1:
            result.append(A.copy())
            return
        for j in range(i, len(A)):
            A[i], A[j] = A[j], A[i]
            directed_permutation(i + 1)
            A[i], A[j] = A[j], A[i]
    result: List[List[int]] = []
    directed_permutation(0)
    return result