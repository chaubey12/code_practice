#include <iostream>
#include <queue>

using namespace std;
struct IteratorCurrentAndEnd{
    bool operator>(const IteratorCurrentAndEnd& that) const{
        return *current > *that.current;
    }
    vector<int>::const_iterator current;
    vector<int>::const_iterator end;
};

vector<int> MergeSortedArrays(const vector<vector<int>> sorted_arrays){
    priority_queue<IteratorCurrentAndEnd, vector<IteratorCurrentAndEnd>, greater<>> min_heap;
    for(const vector<int>& sorted_array : sorted_arrays){
        if(!sorted_array.empty()){
            min_heap.emplace(
                IteratorCurrentAndEnd{sorted_array.cbegin(), sorted_array.cend()}
            );
        }
    }
    vector<int> result;
    while(!min_heap.empty()){
        auto smallest_array = min_heap.top();
        min_heap.pop();
        if(smallest_array.current != smallest_array.end){
            result.emplace_back(*smallest_array.current);
            min_heap.emplace(IteratorCurrentAndEnd{next(smallest_array.current), smallest_array.end});
        }
    }
    return result;
}

int main(){
    vector<int> A {2,4,6,8};
    vector<int> B {1,3,5,7};
    vector<vector<int>> sorted_arrays;
    sorted_arrays.emplace_back(A);
    sorted_arrays.emplace_back(B);
    auto result = MergeSortedArrays(sorted_arrays);
    for(auto item : result){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}