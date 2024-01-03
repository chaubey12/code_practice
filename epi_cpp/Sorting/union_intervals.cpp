#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval{
    struct Endpoint{
        int val;
        bool isClosed;
    };
    Endpoint left, right;
    bool operator<(const Interval& i) const{
        if(left.val != i.left.val){
            return left.val < i.left.val;
        }
        return left.isClosed && !i.left.isClosed;
    }
};

vector<Interval> UnionOfIntervals(vector<Interval>& intervals){
    if(intervals.empty()){
        return {};
    }
    sort(intervals.begin(), intervals.end());
    Interval curr(intervals.front());
    vector<Interval> result;
    for(int i=1; i < intervals.size(); ++i){
        if((intervals[i].left.val < curr.right.val) ||
           ((intervals[i].left.val == curr.right.val) &&
            (intervals[i].left.isClosed || curr.right.isClosed)
           )
        ){
            if((intervals[i].right.val > curr.right.val) ||
               ((intervals[i].right.val == curr.right.val) && 
                (intervals[i].right.isClosed)
               )
            ){
                curr.right = intervals[i].right;
            }
        }else{
            result.emplace_back(curr);
            curr = intervals[i];
        }
    }
    result.emplace_back(curr);
    return result;
}

int main(){
    Interval a = Interval{{0, false}, {3, false}};
    Interval b = Interval{{0, false}, {4, true}};
    Interval c = Interval{{5, true}, {7, false}};
    Interval d = Interval{{5, true}, {8, false}};
    Interval e = Interval{{5, true}, {11, false}};
    Interval f = Interval{{5, true}, {11, true}};
    Interval g = Interval{{12, true}, {16, true}};
    Interval h = Interval{{12, true}, {17, false}};
    vector<Interval> intervals{a, b, c, d, e, f, g, h};
    auto results = UnionOfIntervals(intervals);
    for(auto result : results){
        cout<<(result.left.isClosed?"[":"(") << result.left.val << ", "<<result.right.val<<(result.right.isClosed?"]":")")<<endl; 
    }
    return 0;
}