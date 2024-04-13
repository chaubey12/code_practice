from typing import List

def rearrange(A: List[int])->None:
    for i in range(len(A)):
        A[i: i+2] = sorted(A[i: i+2], reverse=bool(i % 2))


if __name__ == '__main__':
    A = [12, 11, 13, 9, 12, 8, 14, 13, 15]
    rearrange(A)
    for i in A:
        print(i)