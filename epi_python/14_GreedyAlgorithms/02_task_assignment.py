from collections import namedtuple
from typing import List

PairedTasks = namedtuple('PairedTasks', ('task_1', 'task_2'))

def optimum_task_assignment(task_durations: List[int]) -> List[PairedTasks]:
    task_durations.sort()
    return [
        PairedTasks(task_durations[i], task_durations[~i]) for i in range(len(task_durations) // 2)
    ]

if __name__ == '__main__':
    task_duration = [1, 3, 9, 8, 2, 5, 6, 7, 4, 10]
    results = optimum_task_assignment(task_duration)
    for result in results:
        print(result)