import collections

def is_letter_constructible_from_magzine(letter_text: str, magzine_text: str)->bool:
    char_frequency_for_letter = collections.Counter(letter_text)
    for c in magzine_text:
        if c in char_frequency_for_letter:
            char_frequency_for_letter[c] -= 1
            if char_frequency_for_letter[c] == 0:
                del char_frequency_for_letter[c]
                if not char_frequency_for_letter:
                    return True
    return not char_frequency_for_letter