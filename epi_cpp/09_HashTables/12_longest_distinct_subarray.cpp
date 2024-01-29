#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int LongestSubarrayWithDistinctEntries(const vector<int>& A){
    unordered_map<int, size_t> most_recent_occurrence;
    size_t longest_dup_free_subarray_start_idx = 0, result = 0;
    for(size_t i = 0; i < A.size(); ++i){
        auto dup_idx = most_recent_occurrence.emplace(A[i], i);
        if(!dup_idx.second){
            if(dup_idx.first->second >= longest_dup_free_subarray_start_idx){
                result = max(result, i - longest_dup_free_subarray_start_idx);
                longest_dup_free_subarray_start_idx = dup_idx.first->second + 1;
            }
            dup_idx.first->second = i;
        }
    }
    result = max(result, A.size() - longest_dup_free_subarray_start_idx);
    return result;
}

int main(){
    vector<int> A{3, 2, 7, 9, 8, 1, 2, 0, 8, 5, 8};
    cout << LongestSubarrayWithDistinctEntries(A)<<endl;
    return 0;
}