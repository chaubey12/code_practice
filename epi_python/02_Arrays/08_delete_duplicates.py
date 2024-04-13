from typing import List

def delete_duplicates(A: List[int])->int:
    if not A:
        return 0
    write_index = 1
    for i in range(1, len(A)):
        if A[write_index - 1] != A[i]:
            A[write_index] = A[i]
            write_index += 1
    return write_index

if __name__ == '__main__':
    A = [2, 3, 5, 5, 7, 11, 11, 11, 13]
    result = delete_duplicates(A)
    for i in A[:result]:
        print(i)