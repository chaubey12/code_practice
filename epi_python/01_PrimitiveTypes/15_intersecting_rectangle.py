import collections

Rect = collections.namedtuple('Rect', ('x', 'y', 'width', 'height'))

def intersect_rectangle(r1: Rect, r2: Rect)->Rect:
    def is_intersect(r1, r2):
        return (r1.x <= r2.x + r2.width and r1.x + r1.width >= r2.x
                and r1.y <= r2.y + r2.height and r1.y + r1.height >= r2.y)
    if not is_intersect(r1, r2):
        return Rect(0, 0, -1, -1)
    return Rect(
        max(r1.x, r2.x), max(r1.y, r2.y),
        min(r1.x + r1.width, r2.x + r2.width) - max(r1.x, r2.x),
        max(r1.y + r1.height, r2.y + r2.height) - max(r1.y, r2.y)
    ) 

