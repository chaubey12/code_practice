from typing import Deque
from collections import deque

class Queue:
    def __init__(self) -> None:
        self._data: Deque[int] = deque()

    def enqueue(self, x: int) -> None:
        self._data.append(x)
    
    def dequeue(self) -> int:
        return self._data.popleft()
    
    def max(self) -> int:
        return max(self._data)