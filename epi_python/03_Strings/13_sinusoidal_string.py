def snake_string(s: str) -> str:
    result = []
    for i in range(1, len(s), 4):
        result.append(s[i])
    for i in range(0, len(s), 2):
        result.append(s[i])
    for i in range(3, len(s), 4):
        result.append(s[i])
    return ''.join(result)

if __name__ == '__main__':
    s = 'geeksforgeeksgeeksforgeeks'
    result = snake_string(s)
    print(result)