from typing import Deque, Any
from collections import deque

class QueueWithMax:
    def __init__(self):
        self._entries : Deque[Any] = deque
        self._candidates_for_max : Deque[Any] = deque

    def enqueue(self, x: int) -> None:
        self._entries.append(x)
        while self._candidates_for_max and self._candidates_for_max[-1] < x:
            self._candidates_for_max.pop()
        self._candidates_for_max.append(x)

    def dequeue(self):
        result = self._entries.popleft()
        if result == self._candidates_for_max[0]:
            self._candidates_for_max.popleft()
        return result

    def max(self) -> int:
        return self._candidates_for_max[0]