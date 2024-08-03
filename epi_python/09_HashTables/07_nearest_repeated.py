from typing import List, Dict, cast

def find_nearest_reprtition(paragraph: List[str]) -> int:
    word_to_latest_index: Dict[str, int] = {}
    nearest_repeated_distance = float('inf')
    for i, word in enumerate(paragraph):
        if word in word_to_latest_index:
            latest_equal_word = word_to_latest_index[word]
            nearest_repeated_distance = min(nearest_repeated_distance, i - latest_equal_word)
        word_to_latest_index[word] = i
    return cast(int, nearest_repeated_distance) if nearest_repeated_distance != float('inf') else -1

if __name__ == '__main__':
    s = ["All", "work", "and", "no", "play", "makes", "for", "no", "work", "fun", "and", "no", "result"]
    print(find_nearest_reprtition(s))