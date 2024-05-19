def snake_string_pythonic(s):
    return s[1::4] + s[::2] + s[3::4]


if __name__ == '__main__':
    s = 'geeksforgeeksgeeksforgeeks'
    result = snake_string_pythonic(s)
    print(result)