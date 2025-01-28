from typing import List

def search_entry_equal_to_its_index(A: List[int]) -> int:
    left, right = 0, len(A)-1
    while left <= right:
        mid = left + (right - left)//2
        difference = A[mid] - mid
        if difference == 0:
            return mid
        elif difference > 0:
            right = mid - 1
        else:
            left = mid + 1
    return - 1

if __name__=='__main__':
    A = [-2, 0, 2, 3, 6, 7, 9]
    print(search_entry_equal_to_its_index(A))
