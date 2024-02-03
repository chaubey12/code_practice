#include <iostream>
#include <vector>

using namespace std;

int LongestNondecreasingSubsequenceLength(const vector<int>& A){
    vector<int> max_length(A.size(), 1);
    for(int i=1; i < A.size(); ++i){
        for(int j=0; j < i; ++j){
            if(A[i] >= A[j]){
                max_length[i] = max(max_length[i], max_length[j] + 1);
            }
        }
    }
    return *max_element(max_length.begin(), max_length.end());
}


int main(){
    vector<int> A{0, 8, 4, 12, 2, 10, 6, 14, 1, 9};
    cout << LongestNondecreasingSubsequenceLength(A)<<endl;
    return 0;
}