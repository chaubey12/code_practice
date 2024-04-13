from typing import List

def plus_one(A: List[int])->List[int]:
    A[-1] += 1
    for i in reversed(range(1, len(A))):
        if A[i] != 10:
            break
        A[i] = 0
        A[i-1] += 1
    if A[0] == 10:
        A[0] = 0
        A.insert(0, 1)
    return A

if __name__ == '__main__':
    A = [9, 9, 9, 9, 9, 9, 9, 9]
    B = plus_one(A)
    for i in B:
        print(i)