from typing import List

def dutch_flag_partition(pivot_index : int, A: List[int])->None:
    pivot = A[pivot_index]
    smaller, equal, larger = 0, 0, len(A)
    while equal < larger:
        if A[equal] < pivot:
            A[smaller], A[equal] = A[equal], A[smaller]
            smaller, equal = smaller + 1, equal + 1
        elif A[equal] == pivot:
            equal += 1
        else:
            larger -= 1
            A[equal], A[larger] = A[larger], A[equal]

if __name__ == '__main__':
    A = [0, 1, 2, 0, 1, 2, 0, 1, 2]
    pivot_index = 1
    dutch_flag_partition(pivot_index, A)
    for a in A:
        print(a)