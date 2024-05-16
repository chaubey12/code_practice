from typing import List
from collections import Counter
import math


def is_valid_sudoku_pythonic(partial_assignment: List[List[int]]) -> bool:
   region_size = int(math.sqrt(len(partial_assignment)))
   return max(
        Counter(k for i, row in enumerate(partial_assignment)
                for j, c in enumerate(row) if c != 0
                for k in ((i, str(c)), (str(c), j),
                          (i // region_size, j // region_size, str(c)))).values(),
        default=0) <= 1

if __name__ == '__main__':
    partial_assignment = []
    partial_assignment.append([5,3,4,6,7,8,9,1,2])
    partial_assignment.append([6,7,2,1,9,5,3,4,8])
    partial_assignment.append([1,9,8,3,4,2,5,6,7])
    partial_assignment.append([8,5,9,7,6,1,4,2,3])
    partial_assignment.append([4,2,6,8,5,3,7,9,1])
    partial_assignment.append([7,1,3,9,2,4,8,5,6])
    partial_assignment.append([9,6,1,5,3,7,2,8,4])
    partial_assignment.append([2,8,7,4,1,9,6,3,5])
    partial_assignment.append([3,4,5,2,8,6,1,7,9])
    if is_valid_sudoku_pythonic(partial_assignment):
        print("VALID SUDOKU")
    else:
        print("INVALID SUDOKU")