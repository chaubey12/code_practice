import math

def is_palindrome_number(x: int) -> bool:
    if x <= 0:
        return x == 0
    number_digits = math.floor(math.log10(x)) + 1
    msd_mask = 10**(number_digits - 1)
    for i in range(number_digits//2):
        if (x // msd_mask) != (x%10):
            return False
        x %= msd_mask
        x //= 10
        msd_mask //= 100
    return True


if __name__ == '__main__':
    x = 123321
    print(is_palindrome_number(x))