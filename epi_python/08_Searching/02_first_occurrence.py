from typing import List

def search_first_of_k(A: List[int], k: int)->int:
    left, right, result = 0, len(A)-1, -1
    while left <= right:
        mid = (left + right) // 2
        if A[mid] > k:
            right = mid - 1
        elif A[mid] == k:
            result = mid
            right = mid - 1
        else:
            left = mid + 1
    return result

if __name__=='__main__':
    A = [2, 5, 6, 7, 7, 7, 9, 10]
    k = 7
    print(search_first_of_k(A, k))