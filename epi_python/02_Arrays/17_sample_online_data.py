from typing import Iterator, List
import itertools
import random

def online_random_sample(stream: Iterator[int], k: int) -> List[int]:
    running_sample = list(itertools.islice(stream, k))
    num_seen_so_far = k
    for x in stream:
        num_seen_so_far += 1
        idx_to_replace = random.randrange(num_seen_so_far)
        if idx_to_replace < k:
            running_sample[idx_to_replace] = x
    return running_sample

if __name__ == '__main__':
    sample_size = 5
    stream = iter([1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
    sample = online_random_sample(stream, sample_size)
    print("Random sample:", sample)

