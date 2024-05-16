from typing import List

def matrix_in_spiral_order(square_matrix: List[List[int]])->List[int]:
    def matrix_layer_in_clockwise(offset):
        if offset == len(square_matrix) - offset - 1:
            spiral_ordering.append(square_matrix[offset][offset])
            return
        spiral_ordering.extend(square_matrix[offset][offset:-1 - offset])
        spiral_ordering.extend(
            list(zip(*square_matrix))[-1 - offset][offset:-1 - offset])
        spiral_ordering.extend(square_matrix[-1 - offset][-1 - offset:offset:-1])
        spiral_ordering.extend(
            list(zip(*square_matrix))[offset][-1 - offset:offset:-1])

    spiral_ordering: List[int] = []
    for offset in range((len(square_matrix) + 1) // 2):
        matrix_layer_in_clockwise(offset)
    return spiral_ordering

if __name__ == '__main__':
    square_matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
    spiral_ordering = matrix_in_spiral_order(square_matrix)
    print(*spiral_ordering, end=" ")