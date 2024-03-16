import collections

def can_form_palindrome(s: str)->bool:
    return sum(v % 2 for v in collections.Counter(s).values()) <= 1

if __name__ == '__main__':
    if can_form_palindrome('mamamamamxy'):
        print(True)
    else:
        print(False)