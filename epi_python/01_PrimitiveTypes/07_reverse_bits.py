PRECOMPUTED_REVERSE = []
def reverse_bits(x: int)->int:
    mask_size = 16
    bit_mask = 0xFFFF
    return (PRECOMPUTED_REVERSE[x&bit_mask]<<(3*mask_size)
        |  PRECOMPUTED_REVERSE[(x>>mask_size)& bit_mask]<<(2 * mask_size)   
        |  PRECOMPUTED_REVERSE[(x>>2*mask_size)& bit_mask]<<( mask_size) 
        |  PRECOMPUTED_REVERSE[(x>>3*mask_size)& bit_mask]
    )
# This code will not work unless PRECOMPUTED REVERSE is prepopulated
if __name__ == '__main__':
    print(reverse_bits(12))