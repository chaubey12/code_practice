import collections
from typing import List

MinMax = collections.namedtuple('MinMax', ('smallest', 'largest'))

def find_min_max(A: List[int]) -> MinMax:
    def min_max(a, b):
        return MinMax(a, b) if a < b else MinMax(b, a)
    if len(A) <= 1:
        return MinMax(A[0], A[0])
    global_min_max = min_max(A[0], A[1])
    for i in range(2, len(A) - 1, 2):
        local_min_max = min_max(A[i], A[i+1])
        global_min_max = MinMax(
            min(global_min_max.smallest, local_min_max.smallest),
            max(global_min_max.largest, local_min_max.largest))
        if len(A) % 2:
            global_min_max = MinMax(
                min(global_min_max.smallest, A[-1]),
                max(global_min_max.largest, A[-1]))
    return global_min_max

if __name__=='__main__':
    minmax = find_min_max([3, 2, 5, 1, 4])
    print(minmax.smallest, minmax.largest)