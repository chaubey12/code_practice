from typing import Iterator
import itertools

def find_missing_element(stream: Iterator[int])->int:
    num_bucket = 1 << 16
    counter = [0]*num_bucket
    stream, stream_copy = itertools.tee(stream)
    for x in stream:
        upper_part_x = x >> 16
        counter[upper_part_x] += 1
    
    bucket_capacity = 1 << 16
    candidate_bucket = next(
        i for i, c in enumerate(counter) if c < bucket_capacity
    )
    candidates = [0]*bucket_capacity
    stream = stream_copy
    for x in stream_copy:
        upper_part_x = x>>16
        if candidate_bucket == upper_part_x:
            lower_part_x = ((1 << 16) - 1) & x
            candidates[lower_part_x] = 1
    
    for i, v in enumerate(candidates):
        if v == 0:
            return (candidate_bucket << 16) | i

if __name__=='__main__':
    pass