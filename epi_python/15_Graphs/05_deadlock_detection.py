from typing import List

class GraphVertex:

    WHITE, GRAY, BLACK = range(3)

    def __init__(self) -> None:
        self.color = GraphVertex.WHITE
        self.edges: List['GraphVertex'] = []


def is_deadlocked(graph:  List[GraphVertex]) -> bool:
    def has_cycle(cur):
        if cur.color == GraphVertex.GRAY:
            return True
        cur.color = GraphVertex.GRAY
        if any(next.color != GraphVertex.BLACK and has_cycle(next)
               for next in cur.edges):
            return True
        cur.color = GraphVertex.BLACK
        return False
    return any(vertex.color == GraphVertex.WHITE and has_cycle(vertex) for vertex in graph)

if __name__=='__main__':
    v0 = GraphVertex()
    v1 = GraphVertex()
    v2 = GraphVertex()
    v3 = GraphVertex()

    v0.edges.append(v1)
    v1.edges.append(v2)
    v2.edges.append(v3)
    v3.edges.append(v0)

    graph = [v0, v1, v2, v3]
    if is_deadlocked(graph):
        print('Graph is deadlocked')
    else:
        print('Graph is not deadlocked')