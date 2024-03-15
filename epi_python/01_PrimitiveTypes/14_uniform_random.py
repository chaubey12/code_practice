import random

def uniform_random(lower_bound: int, upper_bound: int)->int:
    number_of_outcomes = upper_bound - lower_bound + 1
    while True:
        result, i = 0, 0
        while (1<<i) < number_of_outcomes:
            result = (result<<1)|random.randint(0,1)
            i += 1
        if result < number_of_outcomes:
            break
    return result + lower_bound

if __name__ == '__main__':
    print(uniform_random(10, 20))