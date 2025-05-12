from typing import List
from collections import deque

class GraphVertex:
    def __init__(self):
        self.d = -1
        self.edges: List['GraphVertex'] = []


def is_any_placement_feasible(graph: List[GraphVertex]) -> bool:
    def bfs(s):
        s.d = 0
        q = deque([s])
        while q:
            for t in q[0].edges:
                if t.d == -1:
                    t.d = q[0].d + 1
                    q.append(t)
                elif t.d == q[0].d:
                    return False
        return True
    return all(bfs(v) for v in graph if v.d == -1)