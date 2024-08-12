from typing import List, Set
from collections import namedtuple, Counter

Subarray = namedtuple('Subarray', ('start', 'end'))

def find_smallest_subarray_covering_set(paragraph: List[str], keywords: Set[str]) -> Subarray:
    keywords_to_cover = Counter(keywords)
    result = Subarray(-1, -1)
    remaining_to_cover = len(keywords)
    left = 0
    for right, p in enumerate(paragraph):
        if p in keywords:
            keywords_to_cover[p] -= 1
            if keywords_to_cover[p] >= 0:
                remaining_to_cover -= 1
        while remaining_to_cover == 0:
            if result == (-1, -1) or right - left < result[1] - result[0]:
                result = Subarray(left, right)
            pl = paragraph[left]
            if pl in keywords:
                keywords_to_cover[p] += 1
                if keywords_to_cover[pl] > 0:
                    remaining_to_cover += 1
            left += 1
    return result

if __name__ == '__main__':
    paragraph = ["apple", "banana", "apple", "apple", "dog", "cat", "apple", "dog", "banana", "apple", "cat", "dog"]
    keywords = {"banana", "cat"}
    result = find_smallest_subarray_covering_set(paragraph, keywords)
    print(result)
 

