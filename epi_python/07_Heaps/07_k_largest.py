import heapq

from typing import List

def k_largest_in_binary_heap(A: List[int], k: int) -> List[int]:
    if k <= 0:
        return []
    
    candidate_max_heap = []
    candidate_max_heap.append((-A[0], 0))
    result = []
    for _ in range(k):
        candidate_idx = candidate_max_heap[0][1]
        result.append(-heapq.heappop(candidate_max_heap)[0])
        left_child_idx = 2*candidate_idx + 1
        if left_child_idx < len(A):
            heapq.heappush(candidate_max_heap, (-A[left_child_idx], left_child_idx))
        right_child_idx = 2*candidate_idx + 2
        if right_child_idx < len(A):
            heapq.heappush(candidate_max_heap, (-A[right_child_idx], right_child_idx))
    return result

if __name__ == '__main__':
    k = 4
    arr = [561, 314, 401, 28, 156, 359, 271, 11, 3]
    for i in k_largest_in_binary_heap(arr, k):
        print(i)

