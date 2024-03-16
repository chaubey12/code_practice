from typing import List, DefaultDict
import collections

def find_anagrams(dictionary: List[str])->List[List[str]]:
    sorted_string_to_anagrams : DefaultDict[str, List[str]] = collections.defaultdict(list)
    for s in dictionary:
        sorted_string_to_anagrams[''.join(sorted(s))].append(s)
    return [
        group for group in sorted_string_to_anagrams.values()
        if len(group) >= 2
    ]

if __name__ == '__main__':
    dictionary = ['debitcard', 'elvis', 'silent', 'badcredit', 'lives', 'freedom', 'listen', 'levis', 'money']
    for words in find_anagrams(dictionary):
        for word in words:
            print(word)