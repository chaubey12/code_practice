from typing import List
import math

def is_valid_sudoku(partial_assignment: List[List[int]]) -> bool:
    def has_duplicate(block):
        block = list(filter(lambda x: x != 0, block))
        return len(block) != len(set(block))
    
    n = len(partial_assignment)
    if any(
        has_duplicate([partial_assignment[i][j] for j in range(n)])
        or has_duplicate([partial_assignment[j][i] for j in range(n)])
        for i in range(n)):
        return False
    
    region_size = int(math.sqrt(n))
    return all(not has_duplicate([
        partial_assignment[a][b]
        for a in range(region_size * I, region_size * (I + 1))
        for b in range(region_size * J, region_size * (J + 1))
    ]) for I in range(region_size) for J in range(region_size))

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
    if is_valid_sudoku(partial_assignment):
        print("VALID SUDOKU")
    else:
        print("INVALID SUDOKU")