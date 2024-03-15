def reverse_digits(x: int)->int:
    result, x_remianing = 0, abs(x)
    while x_remianing:
        result = result*10 + x_remianing%10
        x_remianing //= 10
    return -result if x < 0 else result

if __name__ == '__main__':
    print(reverse_digits(-1234))