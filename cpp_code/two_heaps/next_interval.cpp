#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

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

class NextInterval{
public:
    struct startComapre{
        bool operator()(const pair<Interval, int> &x, const pair<Interval, int> &y){
            return x.first.start < y.first.start;
        }
    };
    struct endCompare{
        bool operator()(const pair<Interval, int> &x, const pair<Interval, int> &y){
            return x.first.end < y.first.end;
        }
    };

    static vector<int> findNextInterval(const vector<Interval>& intervals){
        int n = intervals.size();
        priority_queue<pair<Interval, int>, vector<pair<Interval, int>>, startComapre> maxStartHeap;
        priority_queue<pair<Interval, int>, vector<pair<Interval, int>>, endCompare> maxEndHeap;
        for(int i = 0; i < n; i++){
            maxStartHeap.push(make_pair(intervals[i], i));
            maxEndHeap.push(make_pair(intervals[i], i));
        }
        vector<int> result(n);
        for(int i = 0; i < n; i++){
            auto topEnd = maxEndHeap.top();
            maxEndHeap.pop();
            result[topEnd.second] = -1;
            if(!maxStartHeap.empty() && maxStartHeap.top().first.start >= topEnd.first.end){
                auto topStart = maxStartHeap.top();
                maxStartHeap.pop();
                while(!maxStartHeap.empty() && maxStartHeap.top().first.start >= topEnd.first.end){
                    topStart = maxStartHeap.top();
                    maxStartHeap.pop();
                }
                result[topEnd.second] = topStart.second;
                maxStartHeap.push(topStart);
            }
        }
        return result;
    }
};

int main(){
    vector<Interval> intervals{{2, 4}, {5, 8}, {1, 3}, {9, 11}, {0, 1}, {0, 2}};
    auto result = NextInterval::findNextInterval(intervals);
    for(auto in : result){
        cout << in << " ";
    }
    cout << endl;
    return 0;
}