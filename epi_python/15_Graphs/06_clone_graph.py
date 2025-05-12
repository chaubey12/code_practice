from typing import List
from collections import deque

class GraphVertex:
    def __init__(self, label: int) -> None:
        self.label = label
        self.edges: List['GraphVertex'] = []

def clone_graph(graph: GraphVertex) -> GraphVertex:
    if graph is None:
        return None
    
    q = deque([graph])
    vertex_map = {graph: GraphVertex(graph.label)}
    while q:
        v = q.popleft()
        for e in v.edges:
            if e not in vertex_map:
                vertex_map[e] = GraphVertex(e.label)
                q.append(e)
            vertex_map[v].edges.append(vertex_map[e])
    return vertex_map[graph]
