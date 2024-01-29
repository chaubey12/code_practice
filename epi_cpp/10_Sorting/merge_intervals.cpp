#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct Interval{
    int left, right;
};

vector<Interval> AddInterval(vector<Interval>& disjoint_intervals, Interval& new_interval){
    size_t i = 0;
    vector<Interval> result;
    while(i < disjoint_intervals.size() && new_interval.left > disjoint_intervals[i].right){
        result.emplace_back(disjoint_intervals[i++]);
    }

    while(i < disjoint_intervals.size() && new_interval.right >= disjoint_intervals[i].left){
        new_interval = {min(new_interval.left, disjoint_intervals[i].left), 
                        max(new_interval.right, disjoint_intervals[i].right)};
        ++i;
    }
    result.emplace_back(new_interval);
    result.insert(result.end(), disjoint_intervals.begin() + i, disjoint_intervals.end());
    return result;
}

int main(){
    vector<Interval> disjoint_intervals{{-4, -1}, {0, 2}, {3, 6}, {7, 9}, {11, 12}, {14, 17}};
    Interval new_interval {1, 8};
    vector<Interval> result = AddInterval(disjoint_intervals, new_interval);
    for(auto interval : result){
        cout << "{"<<interval.left<<", "<<interval.right<<"}"<<endl;
    }
    return 0;
}
