from typing import List
import collections
import functools

DuplicateAndMissing = collections.namedtuple('DuplicateAndMissing', ('duplicate', 'missing'))

def find_duplicate_missing(A: List[int]) -> DuplicateAndMissing:
    miss_xor_dup = functools.reduce(lambda v, i: v ^ i[0] ^ i[1], enumerate(A), 0)
    differ_bit, miss_or_dup = miss_xor_dup & (~(miss_xor_dup - 1)), 0
    for i, a in enumerate(A):
        if i & differ_bit:
            miss_or_dup ^= i
        if a & differ_bit:
            miss_or_dup ^= a
    return (DuplicateAndMissing(miss_or_dup, miss_or_dup ^ miss_xor_dup)
            if miss_or_dup in A else DuplicateAndMissing(
                miss_or_dup^miss_xor_dup, miss_or_dup))

if __name__=='__main__':
    miss_and_dup = find_duplicate_missing(A=[5, 3, 0, 3, 1, 2])
    print(miss_and_dup.missing, miss_and_dup.duplicate)