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

PRECOMPUTED_PARITY = []
def populate_cache():
    for i in range(2**16):
        PRECOMPUTED_PARITY.append(parity_2(i))

def parity_with_cache(x: int) -> int:
    mask_size = 16
    bit_mask = 0xFFFF
    return (PRECOMPUTED_PARITY[x >> (3*mask_size)]^
        PRECOMPUTED_PARITY[(x >> (2*mask_size)) & bit_mask]^
        PRECOMPUTED_PARITY[(x >> mask_size) & bit_mask]^
        PRECOMPUTED_PARITY[x & bit_mask])

if __name__ == '__main__':
    populate_cache()
    print(parity_with_cache(2**63))