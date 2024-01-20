#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> KLargestInBinaryHeap(const vector<int>& A, int k){
    if(k <= 0){
        return {};
    }
    struct HeapEntry{
        int index, value;
    };
    priority_queue<HeapEntry, vector<HeapEntry>, function<bool(HeapEntry, HeapEntry)>> candidate_max_heap(
        [](const HeapEntry& a, const HeapEntry& b) -> bool{
            return a.value < b.value;
        }
    );
    candidate_max_heap.emplace(HeapEntry{0, A[0]});
    vector<int> result;
    for(int i=0; i < k; ++i){
        int candidate_idx = candidate_max_heap.top().index;
        result.emplace_back(candidate_max_heap.top().value);
        candidate_max_heap.pop();
        int left_child_idx = 2 * candidate_idx + 1;
        if(left_child_idx < A.size()){
            candidate_max_heap.emplace(
                HeapEntry{left_child_idx, A[left_child_idx]}
            );
        }
        int right_child_idx = 2 * candidate_idx + 2;
        if(right_child_idx < A.size()){
            candidate_max_heap.emplace(
                HeapEntry{right_child_idx, A[right_child_idx]}
            );
        }
    }
    return result;
}

int main(){
    vector<int> A{561, 314, 401, 28, 156, 359, 271, 11, 3};
    int k=4;
    auto result = KLargestInBinaryHeap(A, k);
    for(auto el : result){
        cout << el << " ";
    }
    cout << endl;
    return 0;
}