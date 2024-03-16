import functools

def string_hash(s: str, modulus: int)->int:
    mult = 997
    return functools.reduce(lambda v, c: (v * mult + ord(c)) % modulus, s, 0) 

if __name__ == '__main__':
    name = 'madhup'
    print(string_hash(name, 12))