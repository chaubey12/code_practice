#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Interval{
public:
    int start=0;
    int end=0;
    Interval(int start, int end){
        this->start = start;
        this->end = end;
    }
};

class MergeIntervals{
public:
    static vector<Interval> merge(vector<Interval>& intervals){
        if(intervals.size() < 2){
            return intervals;
        }
        vector<Interval> mergedIntervals;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){ return a.start < b.start; });
        vector<Interval>::const_iterator itr = intervals.begin();
        Interval interval = *itr++;
        int start = interval.start;
        int end = interval.end;
        while(itr != intervals.end()){
            interval = *itr++;
            if(interval.start > end){
                mergedIntervals.push_back({start, end});
                start = interval.start;
                end = interval.end;
            }else{
                end = max(end, interval.end);
            }
        }
        mergedIntervals.push_back({start, end});
        return mergedIntervals;
    }
};

int main(){
    vector<Interval> intervals = {{2, 3}, {5, 7}, {8,10}, {6, 9}};
    auto result = MergeIntervals::merge(intervals);
    for(auto interval : result){
        cout << "{" << interval.start << "," << interval.end << "}" << endl;
    }
    return 0;
}