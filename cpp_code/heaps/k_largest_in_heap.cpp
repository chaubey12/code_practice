#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> KLargestInBinaryHeap(const vector<int>& A, int k){
    if(k <= 0){
        return {};
    }
    struct HeapEntry{
        int index, value;
    };

    priority_queue<HeapEntry, vector<HeapEntry>, function<bool(HeapEntry, HeapEntry)>>
        candidate_max_heap([](const HeapEntry& a, const HeapEntry& b)->bool{
            return a.value < b.value;
        });
    candidate_max_heap.emplace(HeapEntry{0, A[0]});
    vector<int> result;
    for(int i = 0; i < k; i++){
        int candidate_idx = candidate_max_heap.top().index;
        result.emplace_back(candidate_max_heap.top().value);
        candidate_max_heap.pop();
        int left_candidate_idx = 2*candidate_idx + 1;
        if(left_candidate_idx < A.size()){
            candidate_max_heap.emplace(HeapEntry{left_candidate_idx, A[left_candidate_idx]});
        }
        int right_candidate_idx = 2*candidate_idx + 2;
        if(right_candidate_idx < A.size()){
            candidate_max_heap.emplace(HeapEntry{right_candidate_idx, A[right_candidate_idx]});
        }
    }
    return result;
}

int main(){
    vector<int> heap = {17, 15, 13, 9, 6, 5, 10, 4, 8, 3, 1};
    int k = 4;
    auto result = KLargestInBinaryHeap(heap, k);
    for(auto elem : result){
        cout << elem << endl;
    }
    return 0;
}