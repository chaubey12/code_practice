from typing import Iterator, List
from collections import namedtuple

def examine_buildings_with_sunset(sequence: Iterator[int]) -> List[int]:
    BuildingWithHeight = namedtuple('BuildingWithHeight', ('id', 'height'))
    candidates : List[BuildingWithHeight] = []
    for building_idx, building_height in enumerate(sequence):
        while candidates and building_height >= candidates[-1].height:
            candidates.pop()
        candidates.append(BuildingWithHeight(building_idx, building_height))
    return [c.id for c in reversed(candidates)]

if __name__ == '__main__':
    buildings = [3, 7, 8, 3, 6, 1]

    print("Building heights (East → West):", buildings)

    result = examine_buildings_with_sunset(iter(buildings))

    print("Buildings that can see sunset (by index):", result)
    print("Heights of those buildings:", [buildings[i] for i in result])