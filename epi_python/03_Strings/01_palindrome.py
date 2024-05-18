def is_palindrome(s: str) -> bool:
    return all(s[i] == s[~i] for i in range(len(s) // 2))

if __name__ == '__main__':
    if is_palindrome('abcba') == True:
        print("PALINDROME")
    else:
        print("NOT A PALINDROME")