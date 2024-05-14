from typing import List, Dict
import random

def random_subset(n: int, k: int)->List[int]:
    changed_elements: Dict[int, int] = {}
    for i in range(k):
        rand_idx = random.randrange(i, n)
        rand_idx_mapped = changed_elements.get(rand_idx, rand_idx)
        i_mapped = changed_elements.get(i, i)
        changed_elements[rand_idx] = i_mapped
        changed_elements[i] = rand_idx_mapped
    return [changed_elements[i] for i in range(k)]

if __name__ == '__main__':
    subset = random_subset(6, 4)
    print(*subset, end="\n")