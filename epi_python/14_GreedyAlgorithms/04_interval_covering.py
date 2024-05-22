from collections import namedtuple
from typing import List
import operator

Interval = namedtuple('Intervl', ('left', 'right'))

def find_minimum_visits(intervals: List[Interval]) -> int:
    intervals.sort(key=operator.attrgetter('right'))
    last_visit_time, num_visits = float('-inf'), 0
    for interval in intervals:
        if interval.left > last_visit_time:
            last_visit_time = interval.right
            num_visits += 1
    return num_visits

if __name__ == '__main__':
    intervals = [Interval(1, 2), Interval(2, 3), Interval(3, 4), Interval(2, 3), Interval(3, 4), Interval(4, 5)]
    print(find_minimum_visits(intervals))

