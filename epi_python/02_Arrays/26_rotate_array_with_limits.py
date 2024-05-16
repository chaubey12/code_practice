from typing import List

class RotateMatrix:
    def __init__(self, square_matrix: List[List[int]]) -> None:
        self._square_matrix = square_matrix

    def read_entry(self, i: int, j: int) -> int:
        return self._square_matrix[~j][i]
    
    def write_entry(self, i: int, j: int, v: int) -> None:
        self._square_matrix[~j][i] = v