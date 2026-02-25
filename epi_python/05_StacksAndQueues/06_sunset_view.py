from typing import Iterator, List
from collections import namedtuple

def examine_buildings_with_sunset(sequence: Iterator[int]) -> List[int]:
    BuildingWithHeight = namedtuple('BuildingWithHeight', ('id', 'height'))
    candidates = List[BuildingWithHeight] = []
    for building_idx, building_height in enumerate(sequence):
        while candidates and building_height >= candidates[-1].height:
            candidates.pop()
        candidates.append(BuildingWithHeight(building_idx, building_height))
    return [c.id for c in reversed(candidates)]

if __name__ == '__main__':
    buildings = [7, 10, 6, 17, 8]
    print(examine_buildings_with_sunset(buildings))