def square_root(k: int)->int:
    left, right = 0, k
    while left <= right:
        mid = (left + right) // 2
        mid_squared = mid*mid
        if mid_squared <= k:
            left = mid + 1
        else:
            right = mid - 1
    return left - 1

if __name__=='__main__':
    print(square_root(144))