
def count_bits(x : int)->bool:
    num_bits = 0
    while x :
        num_bits += x&1
        x >>= 1
    return num_bits

if __name__ == '__main__':
    n = 255
    print(count_bits(n))