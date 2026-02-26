from typing import List
from collections import namedtuple

class Stack:
    ElementWithCachedMax = namedtuple('ElementWithCachedMax', ('element', 'max'))

    def __init__(self) -> None:
        self._element_with_cached_max: List[Stack.ElementWithCachedMax] = []

    def empty(self) -> bool:
        return len(self._element_with_cached_max) == 0

    def max(self) -> int:
        return self._element_with_cached_max[-1].max

    def pop(self) -> int:
        return self._element_with_cached_max.pop().element

    def push(self, x: int) -> None:
        self._element_with_cached_max.append(
            self.ElementWithCachedMax(x, x if self.empty() else max(x, self.max()))
        )


class QueueWithMax:
    def __init__(self) -> None:
        self._enqueue, self._dequeue = Stack(), Stack()

    def enqueue(self, x: int) -> None:
        self._enqueue.push(x)

    def dequeue(self) -> int:
        if self._dequeue.empty():
            while not self._enqueue.empty():
                self._dequeue.push(self._enqueue.pop())
        return self._dequeue.pop() 

    def max(self) -> int:
        if not self._enqueue.empty():
            return self._enqueue.max() if self._dequeue.empty() else max(
                self._enqueue.max(), self._dequeue.max())
        return self._dequeue.max()
