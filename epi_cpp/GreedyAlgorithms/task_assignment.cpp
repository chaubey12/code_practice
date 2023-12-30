#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct PairedTasks{
    int task_1, task_2;
};

vector<PairedTasks> OptimumTaskAssignment(vector<int> task_duration){
    sort(task_duration.begin(), task_duration.end());
    vector<PairedTasks> optimum_assignments;
    for(int i=0, j=task_duration.size() - 1; i < j; ++i, --j){
        optimum_assignments.emplace_back(
            PairedTasks{task_duration[i], task_duration[j]}
        );
    }
    return optimum_assignments;
}


int main(){
    vector<int> task_duration = {1,3,9,8,2,5,6,7,4,10};
    auto result = OptimumTaskAssignment(task_duration);
    for(auto item : result){
        cout <<"{"<<item.task_1 << ","<<item.task_2<<"}"<<endl;
    }
    return 0;
}