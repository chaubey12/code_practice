#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct IteratorCurrentAndEnd{
    bool operator>(const IteratorCurrentAndEnd& that)const{
        return *current > *that.current;
    }
    vector<int>::const_iterator current;
    vector<int>::const_iterator end;
};

vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays){
    priority_queue<IteratorCurrentAndEnd, vector<IteratorCurrentAndEnd>, greater<>> min_heap;
    for(const vector<int>& sorted_array : sorted_arrays){
        min_heap.emplace(
            IteratorCurrentAndEnd{sorted_array.begin(), sorted_array.end()}
        );
    }
    vector<int> result;
    while(!min_heap.empty()){
        auto smallest_array = min_heap.top();
        min_heap.pop();
        if(smallest_array.current != smallest_array.end){
            result.emplace_back(*smallest_array.current);
            min_heap.emplace(
                IteratorCurrentAndEnd{next(smallest_array.current), smallest_array.end});
        }
    }
    return result;
}


vector<int> SortKIncreasingDecreasing(const vector<int>& A){
    vector<vector<int>> sorted_subarrays;
    typedef enum {INCREASING, DECREASING} SubarrayType;
    SubarrayType subarray_type = INCREASING;
    int start_idx = 0;
    for(int i=1; i <= A.size(); ++i){
        if(i == A.size() ||
           (A[i-1] < A[i] && subarray_type == DECREASING) ||
           (A[i-1] >= A[i] && subarray_type == INCREASING)){
            if(subarray_type == INCREASING){
                sorted_subarrays.emplace_back(A.cbegin() + start_idx, A.cbegin() + i);
            }else{
                sorted_subarrays.emplace_back(A.crbegin() + A.size() - i, A.crbegin() + A.size() - start_idx);
            }
            start_idx = i;
            subarray_type = {subarray_type == INCREASING ? DECREASING : INCREASING};
        }
    }
    return MergeSortedArrays(sorted_subarrays);
}

int main(){
    vector<int> A{57, 131, 493, 294, 221, 339, 418, 452, 442, 190};
    auto result = SortKIncreasingDecreasing(A);
    for(auto item : result){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}