from typing import List
import itertools
import random
import bisect

def nonuniform_random_number_generation(values: List[int], probabilities: List[float]) -> int:
    prefix_sum_of_probabilities = list(itertools.accumulate(probabilities))
    interval_idx = bisect.bisect(prefix_sum_of_probabilities, random.random())
    return values[interval_idx]

if __name__ == '__main__':
    values = [3, 5, 7, 11]
    probabilities = [9./18, 6./18, 2./18, 1./18]
    rand = nonuniform_random_number_generation(values, probabilities)
    print(rand)

