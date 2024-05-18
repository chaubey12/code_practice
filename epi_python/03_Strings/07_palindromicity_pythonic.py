
def is_palindrome_pythonic(s: str)->bool:
    return all(a == b for a, b in zip(
        map(str.lower, filter(str.isalnum, s)),
        map(str.lower, filter(str.isalnum, reversed(s)))))

if __name__ == '__main__':
    s = "A man, a plan, a canal, Panama."
    if is_palindrome_pythonic(s):
        print("PALINDROME")
    else:
        print("NOT A PALINDROME")