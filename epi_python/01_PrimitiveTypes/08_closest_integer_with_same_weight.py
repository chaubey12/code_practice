def closest_int_same_bit_count(x: int)->int:
    num_unsigned_bits = 64
    for i in range(num_unsigned_bits - 1):
        if ((x>>i)&1) != ((x>>(i+1))&1):
            x ^= (i << i) | (i << (i+1))
            return x
    return ValueError('All bits are 0 or 1')

if __name__ == '__main__':
    print(closest_int_same_bit_count(0))