from typing import List

def find_maximum_subarray(A: List[int]) -> int:
    max_seen = max_end = 0
    for a in A:
        max_end = max(0, max_end + a)
        max_seen = max(max_seen, max_end)
    return max_seen

if __name__ == "__main__":
    A = [904, 20, 523, 12. -335, -385, -124, 481, -31]
    print(f"Maximum subarray sum is {find_maximum_subarray(A)}")