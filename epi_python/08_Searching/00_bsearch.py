from typing import List

def bsearch(t: int, A: List[int])->int:
    L, U = 0, len(A)-1
    while L <= U:
        M = (L + U)//2
        if A[M] < t:
            L = M + 1
        elif A[M] == t:
            return M
        else:
            R = M - 1
    return -1