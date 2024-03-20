class Student:
    def __init__(self, name: str, grade_point_average: float) -> None:
        self.name = name
        self.grade_point_average = grade_point_average

    def __lt__(self, other: 'Student')->bool:
        return self.name < other.name
    
students = [
    Student('A', 4.0),
    Student('C', 3.0),
    Student('B', 2.0),
    Student('D', 3.2)
]

students_sort_by_name = sorted(students)

students.sort(key=lambda student: student.grade_point_average)