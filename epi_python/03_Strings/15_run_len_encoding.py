def decoding(s: str) -> str:
    count, result = 0, []
    for c in s:
        if c.isdigit():
            count = count * 10 + int(c)
        else:
            result.append(c * count)
            count = 0
    return ''.join(result)

def encoding(s: str) -> str:
    result, count = [], 1
    for i in range(1, len(s) + 1):
        if i == len(s) or s[i] != s[i - 1]:
            result.append(str(count) + s[i - 1])
            count = 1
        else:
            count += 1
    return ''.join(result)

if __name__ == '__main__':
    s = "aaaabcccaa"
    e = encoding(s)
    print(e)
    s = decoding(e)
    print(s)