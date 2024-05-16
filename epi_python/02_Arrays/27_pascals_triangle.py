from typing import List

def generate_pascal_triangle(n: int) -> List[List[int]]:
    result = [[1]*(i + 1) for i in range(n)]
    for i in range(n):
        for j in range(1, i):
            result[i][j] = result[i-1][j-1] + result[i-1][j]
    return result


if __name__ == '__main__':
    result = generate_pascal_triangle(5)
    print(*result, end="\n")