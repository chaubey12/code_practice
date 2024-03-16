from typing import Iterator, List
import heapq
import itertools

def top_k(k: int, stream: Iterator[str])->List[str]:
    min_heap = [(len(s), s) for s in itertools.islice(stream, k)]
    heapq.heapify(min_heap)
    for next_string in stream:
        heapq.heappushpop(min_heap, (len(next_string), next_string))
    return [p[1] for p in heapq.nsmallest(k, min_heap)]

if __name__ == '__main__':
    strings = ["this", "is", "the", "way", "street", "approximate"]
    string_iter = iter(strings)
    for s in top_k(3, string_iter):
        print(s)
    