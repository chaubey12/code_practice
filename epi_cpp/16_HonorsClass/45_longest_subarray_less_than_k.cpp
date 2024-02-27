#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int FindLongestSubarrayLessThanEqualK(const vector<int>& A, int k){
    vector<int> prefix_sum;
    partial_sum(A.cbegin(), A.cend(), back_inserter(prefix_sum));
    if(prefix_sum.back() <= k){
        return A.size();
    }
    vector<int> min_prefix_sum(A.size());
    min_prefix_sum.back() = prefix_sum.back();
    for(int i=min_prefix_sum.size() - 2; i >= 0; --i){
        min_prefix_sum[i] = min(prefix_sum[i], min_prefix_sum[i+1]);
    }
    int a=0, b=0, max_length=0;
    while(a < A.size() && b < A.size()){
        int min_curr_sum = (a > 0)? min_prefix_sum[b] - prefix_sum[a-1] : min_prefix_sum[b];
        if(min_curr_sum <= k){
            int curr_length = b - a + 1;
            if(curr_length > max_length){
                max_length = curr_length;
            }
            ++b;
        }else{
            ++a;
        } 
    }
    return max_length;
}

int  main(){
    vector<int> A{431, -15, 639, -14, 565, -924, 635, 167, -70};
    int k = 184;
    cout << "Max Length : "<<FindLongestSubarrayLessThanEqualK(A, k)<<endl;
    return 0;
}