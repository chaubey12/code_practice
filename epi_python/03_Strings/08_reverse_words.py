from typing import List

def reverse_words(s: List[str]) -> None:
    def reverse_range(s, start, finish):
        while start < finish:
            s[start], s[finish] = s[finish], s[start]
            start, finish = start + 1, finish - 1
    
    reverse_range(s, 0, len(s) - 1)
    start = 0
    while True:
        finish = start
        while finish < len(s) and s[finish] != ' ':
            finish += 1
        if finish == len(s):
            break
        reverse_range(s, start, finish - 1)
        start = finish + 1
    reverse_range(s, start, len(s) - 1)

if __name__ == '__main__':
    s = ['A','l','i','c','e',' ' ,'l','i','k','e','s', ' ','B','o','b']
    print(s)
    reverse_words(s)
    print(s)