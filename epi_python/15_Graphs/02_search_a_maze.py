import collections
from typing import List

WHITE, BLACK = range(2)

Coordinate = collections.namedtuple('Coordinate', ('x', 'y'))

def search_maze(maze: List[List[int]], s: Coordinate, e: Coordinate)->List[Coordinate]:
    def search_maze_helper(cur):
        if not (0 <= cur.x < len(maze) and 0 <= cur.y < len(maze[cur.x])
                and maze[cur.x][cur.y] == WHITE):
            return False
        path.append(cur)
        maze[cur.x][cur.y] = BLACK
        if cur == e:
            return True
        if any(
            map(search_maze_helper, 
                map(Coordinate, (cur.x - 1, cur.x + 1, cur.x, cur.x),
                    (cur.y, cur.y, cur.y - 1, cur.y + 1)))):
            del path[-1]
            return False
    path: List[Coordinate] = []
    search_maze_helper(s)
    return path