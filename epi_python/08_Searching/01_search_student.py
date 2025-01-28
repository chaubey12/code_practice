import collections
import bisect
from typing import List, Callable, Tuple

Student = collections.namedtuple('Student', ('name', 'grade_point_average'))

def comp_gpa(student):
    return (-student.grade_point_average, student.name)

def search_student(students: List[Student], target: Student, 
                   comp_gpa: Callable[[Student], Tuple[float, str]]):
    i = bisect.bisect_left([comp_gpa(s) for s in students], comp_gpa(target))
    return 0 <= i < len(students) and students[i] == target

if __name__ == '__main__':
    students = [
        Student(name="Alice", grade_point_average=3.9),
        Student(name="Bob", grade_point_average=3.7),
        Student(name="Charlie", grade_point_average=3.8),
    ]
    students.sort(key=comp_gpa)
    target = Student(name="Alice", grade_point_average=3.9)
    print(search_student(students, target, comp_gpa))