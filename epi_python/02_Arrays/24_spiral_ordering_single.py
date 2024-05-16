from typing import List

def matrix_in_spiral_order(square_matrix: List[List[int]])->List[int]:
    shift = ((0, 1), (1, 0), (0, -1), (-1, 0))
    direction = x = y = 0
    spiral_ordering = []

    for _ in range(len(square_matrix)**2):
        spiral_ordering.append(square_matrix[x][y])
        square_matrix[x][y] = 0
        next_x, next_y = x + shift[direction][0], y + shift[direction][1]
        if (next_x not in range(len(square_matrix))
            or next_y not in range(len(square_matrix))
            or square_matrix[next_x][next_y] == 0):
            direction = (direction + 1) & 3
            next_x, next_y = x + shift[direction][0], y + shift[direction][1]
        x, y = next_x, next_y
    return spiral_ordering

if __name__ == '__main__':
    square_matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
    spiral_ordering = matrix_in_spiral_order(square_matrix)
    print(*spiral_ordering, end=" ")