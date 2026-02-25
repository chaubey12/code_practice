def is_well_formed(s: str) -> bool:
    left_chars, lookup = [], {'(':')', '{':'}', '[':']'}
    for c in s:
        if c in lookup:
            left_chars.append(c)
        elif not left_chars or lookup[left_chars.pop()] != c:
            return False
    return not left_chars

if __name__ == '__main__':
    exp = "(()[]){}"
    if is_well_formed(exp):
        print("Well formed expression")
    else:
        print("Not well formed expression")
    exp = "(()][){}"
    if is_well_formed(exp):
        print("Well formed expression")
    else:
        print("Not well formed expression")

