#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student{
    string name;
    double grade_point_average;
};

const static function<bool(const Student&, const Student&)> CompGPA = []
    (const Student& a, const Student& b) -> bool{
        if(a.grade_point_average != b.grade_point_average){
            return a.grade_point_average < b.grade_point_average;
        }
        return a.name < b.name;
    };

bool SearchStudent(const vector<Student>& students, const Student& target,
    const function<bool(const Student&, const Student&)>& CompGPA){
    return binary_search(students.begin(), students.end(), target, CompGPA);
}

int main(){
    vector<Student> students{{"abc", 90.5}, {"def", 90.1}, {"ghi", 90.4}, {"jkl", 90.3}, {"mno", 90.2}};
    sort(students.begin(), students.end(), [](const Student& a, const Student& b){ return a.grade_point_average < b.grade_point_average; });
    if(SearchStudent(students, {"jkl", 90.3}, CompGPA)){
        cout << "FOUND"<<endl;
    }else{
        cout << "NOT FOUND"<<endl;
    }
    return 0;
}