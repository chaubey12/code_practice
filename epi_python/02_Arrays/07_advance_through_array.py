from typing import List

def can_reach_end(A: List[int]) -> bool:
    furthest_reach_so_far, last_index = 0, len(A) - 1
    i = 0
    while i <= furthest_reach_so_far and furthest_reach_so_far <= last_index:
        furthest_reach_so_far = max(furthest_reach_so_far, A[i] + i)
        i += 1
    return furthest_reach_so_far >= last_index

if __name__ == '__main__':
    A = [3, 3, 1, 0, 2, 0, 1]
    if can_reach_end(A):
        print("CAN REACH")
    else:
        print("CANNOT REACH")
    A = [3, 2, 0, 0, 2, 0, 1]
    if can_reach_end(A):
        print("CAN REACH")
    else:
        print("CANNOT REACH")