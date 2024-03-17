from typing import List

MAPPING = ('0', '1', 'ABC', 'DEF', 'GHI', 'JKL', 'MNO', 'PQRS', 'TUV', 'WXYZ')

def phone_mnemonic(phone_number: str)->List[str]:
    def phone_mnemonic_helper(digit):
        if digit == len(phone_number):
            mnemonics.append(''.join(partial_mnemonic))
        else:
            for c in MAPPING[int(phone_number[digit])]:
                partial_mnemonic[digit] = c
                phone_mnemonic_helper(digit + 1)
    mnemonics: List[str] = []
    partial_mnemonic = [0] * len(phone_number)
    phone_mnemonic_helper(0)
    return mnemonics