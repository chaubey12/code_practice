from typing import List, Tuple
import heapq
import itertools

def merge_sorted_arrays(sorted_arrays: List[List[int]])->List[int]:
    min_heap = List[Tuple[int, int]]
    