#include <iostream>
#include <vector>

using namespace std;

struct Subarray{
    int start=0, end=0;
};

Subarray FindLongestIncreasingSubarray(const vector<int>& A){
    int max_length = 1;
    Subarray ans;
    int i=0;
    while(i < A.size() - max_length){
        bool is_skippable = false;
        for(int j = i + max_length; j > i; --j){
            if(A[j-1] >= A[j]){
                if(A[j-1] >= A[j]){
                    i = j;
                    is_skippable = true;
                    break;
                }
            }
        }
        if(!is_skippable){
            i += max_length;
            while(i < A.size() && A[i-1] < A[i]){                    
                ++i;
                ++max_length;
            }
            ans = {i - max_length, i-1};
        }
    }
    return ans;
}

int main(){
    vector<int> A{2, 11, 3, 5, 13, 7, 19, 17, 23};
    auto result = FindLongestIncreasingSubarray(A);
    cout << "{"<< result.start << ", "<< result.end << "}"<<endl;
    return 0;
}