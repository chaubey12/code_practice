from typing import List, Iterator
import heapq
import itertools

def sort_approximately_sorted_array(sequence: Iterator[int], x: int)->List[int]:
    min_heap : List[int] = []
    for x in itertools.islice(sequence, k):
        heapq.heappush(min_heap, x)
    
    result = []
    for x in sequence:
        smallest = heapq.heappushpop(min_heap, x)
        result.append(smallest)

    while min_heap:
        smallest = heapq.heappop(min_heap)
        result.append(smallest)

    return result

if __name__ == '__main__':
    sequence, k = [3, -1, 2, 6, 4, 5, 8], 2
    for i in sort_approximately_sorted_array(iter(sequence), k):
        print(i)