from typing import List

def rotate_matrix(square_matrix : List[List[int]]) -> None:
    matrix_size = len(square_matrix) - 1
    for i in range(len(square_matrix) // 2):
        for j in range(i, matrix_size - i):
            (square_matrix[i][j], square_matrix[~j][i], square_matrix[~i][~j], 
             square_matrix[j][~i]) = (square_matrix[~j][i],
                                      square_matrix[~i][~j],
                                      square_matrix[j][~i],
                                      square_matrix[i][j])

if __name__ == '__main__':
    square_matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
    print(*square_matrix, end="\n")
    rotate_matrix(square_matrix)
    print(*square_matrix, end="\n")