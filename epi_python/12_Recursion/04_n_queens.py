from typing import List

def n_queens(n: int)->List[List[int]]:
    def solve_n_queens(row):
        if row == n:
            result.append(col_placement.copy())
            return
        for col in range(n):
            if all(
                abs(c - col) not in (0, row-1)
                for i, c in enumerate(col_placement[:row])):
                col_placement[row] = col
                solve_n_queens(row + 1)
    result : List[List[int]] = []
    col_placement = [0]*n
    solve_n_queens(0)
    return result