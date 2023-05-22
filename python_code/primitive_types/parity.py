def parity_1(x: int) -> int:
    result = 0
    while x:
        result ^= x&1
        x >>= 1
    return result

def parity_2(x : int) -> int:
    result = 0
    while x:
        result ^= 1
        x &= x-1
    return result

if __name__ == '__main__':
    print(parity_1(31))
    print(parity_1(31))