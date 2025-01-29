from typing import List

def search_smallest(A: List[int]) -> int:
    left, right = 0,len(A)-1
    while left < right:
        mid = (left + right) // 2
        if A[mid] > A[right]:
            left = mid + 1
        else:
            right = mid
    return left

if __name__=='__main__':
    A = [378, 478, 550, 631, 103, 203, 220, 234, 279, 368]
    print(A[search_smallest(A)])