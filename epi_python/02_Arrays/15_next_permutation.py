from typing import List

def next_permutation(perm: List[int])->List[int]:
    inversion_point = len(perm) - 2
    while (inversion_point >= 0
           and perm[inversion_point] >= perm[inversion_point + 1]):
        inversion_point -= 1
    if inversion_point == -1:
        return []
    for i in reversed(range(inversion_point + 1, len(perm))):
        if perm[i] > perm[inversion_point]:
            perm[inversion_point], perm[i] = perm[i], perm[inversion_point]
            break
    perm[inversion_point + 1:] = reversed(perm[inversion_point + 1:])
    return perm

if __name__ == '__main__':
    perm = [4, 3, 1, 2]
    result = next_permutation(perm)
    for i in result:
        print(i)