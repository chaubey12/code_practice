import collections
from typing import List

class Stack:
    ElementWithCachedMax = collections.namedtuple('ElemenetWithCachedMax', ('element', 'max'))

    def __init__(self):
        self._element_with_cached_max: List[Stack.ElementWithCachedMax] = []

    def empty(self) -> bool:
        return len(self._element_with_cached_max) == 0

    def max(self) -> int:
        return self._element_with_cached_max[-1].max

    def pop(self) -> int:
        return self._element_with_cached_max.pop().element

    def push(self, x: int) -> None:
        self._element_with_cached_max.append(
            self.ElementWithCachedMax(x, x 
                                      if self.empty() else max(x, self.max()))
        )

if __name__=='__main__':
    stack = Stack()
    stack.push(2)
    stack.push(8)
    stack.push(4)
    stack.push(18)
    stack.push(1)
    while not stack.empty():
        print('max=', stack.max())
        stack.pop()