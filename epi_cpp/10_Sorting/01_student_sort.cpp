#include <iostream>
#include <algorithm>
#include <memory>
#include <vector>

using namespace std;

struct Student{
    bool operator < (const Student& that) const { return name < that.name;}
    string name;
    double grade_point_average;
};

void SortByGPA(vector<Student>* students){
    sort(students->begin(), students->end(), [](const Student& a, const Student& b)->bool{
        return a.grade_point_average >= b.grade_point_average;
    });
}

void SortByName(vector<Student>* students){
    sort(students->begin(), students->end());
}

int main(){
    Student A = {"madhup", 97.9};
    Student B = {"shashi", 99.2};
    Student C = {"sonal", 99.21};
    Student D = {"aid", 99.213};
    vector<Student> students{A, B, C, D};
    SortByGPA(&students);
    cout << "SORTED BY GRADE"<<endl;
    for(auto student : students){
        cout << student.name <<" "<<student.grade_point_average<<endl;
    }
    cout << "SORTED BY NAME"<<endl;
    SortByName(&students);
    for(auto student : students){
        cout << student.name <<" "<<student.grade_point_average<<endl;
    }
    return 0;
}
