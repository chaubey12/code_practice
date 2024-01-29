#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Interval{
    int left, right;
};

vector<int> FindMinimumVisits(vector<Interval> intervals){
    if(intervals.empty()){
        return {};
    }
    sort(intervals.begin(), intervals.end(), 
        [](const Interval& a, const Interval& b) -> bool{
            return a.right < b.right;
        });
    vector<int> visits;
    int last_visit_time = intervals.front().right;
    visits.emplace_back(last_visit_time);
    for(const Interval& interval : intervals){
        if(interval.left > last_visit_time){
            last_visit_time = interval.right;
            visits.emplace_back(last_visit_time);
        }
    }
    return visits;
}

int main(){
    vector<Interval> intervals = {{1,2},{2,3},{3,4},{2,3},{3,4},{4,5}};
    auto visits = FindMinimumVisits(intervals);
    for(auto visit : visits){
        cout << visit << " ";
    }
    cout << endl;
    return 0;
}