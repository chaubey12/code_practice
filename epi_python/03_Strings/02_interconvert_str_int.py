import functools
import string

def int_to_string(x: int) -> str:
    is_negative = False
    if x < 0:
        x, is_negative = -x, True
    s = []
    while True:
        s.append(chr(ord('0') + x % 10))
        x //= 10
        if x == 0:
            break
    return ('-' if is_negative else '') + ''.join(reversed(s))

def string_to_int(s: str) -> int:
    return functools.reduce(
        lambda running_sum, c: running_sum * 10 + string.digits.index(c),
        s[s[0] == '-':], 0) * (-1 if s[0] == '-' else 1)

if __name__ == '__main__':
    x = 1234
    s = int_to_string(x)
    print(s)

    s1 = '-1001'
    x1 = string_to_int(s1)
    print(x1)
    s2 = '2098'
    x2 = string_to_int(s2)
    print(x2)
