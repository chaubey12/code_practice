def parity(x: int) -> int:
    result = 0
    while x:
        result ^= x&1
        x >>= 1
    return result


if __name__ == '__main__':
    print('parity ' + str(parity(7)))