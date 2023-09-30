#include <iostream>
#include <vector>
#include <algorithm>

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
    static vector<Interval> merge(const vector<Interval>& intervals){
        vector<Interval> result;
        sort(intervals.begin(), intervals.end(), [](const Interval& x, const Interval& y){ return x.start < y.start;});

        return result;
    }
};

int main(){
    vector<Interval> intervals = {{1,4}, {2,5}, {7,9}};

    return 0;
}