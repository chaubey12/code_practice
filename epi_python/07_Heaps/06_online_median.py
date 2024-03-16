import heapq
from typing import List, Iterator

def online_median(sequence: Iterator[int])->List[int]:
    min_heap: List[int] = []
    max_heap: List[int] = []
    result = []

    for x in sequence:
        heapq.heappush(max_heap, -heapq.heappushpop(min_heap, x))
        if len(max_heap) > len(min_heap):
            heapq.heappush(min_heap, -heapq.heappop(max_heap))
        result.append(0.5*(min_heap[0] + (-max_heap[0]))
                      if len(min_heap) == len(max_heap) else min_heap[0])
    return result

if __name__ == '__main__':
    stream = [1,2,3,5]
    medians = online_median(iter(stream))
    for i in medians:
        print(i)