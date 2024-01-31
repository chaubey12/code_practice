#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int ComputeDistanceBetweenPrefixes(const string& A, int A_idx, const string& B, int B_idx, 
                                   vector<vector<int>>* distance_between_prefix_ptr){
    vector<vector<int>>& distance_between_prefix = *distance_between_prefix_ptr;
    if(A_idx < 0){
        return B_idx + 1;
    }
    if(B_idx < 0){
        return A_idx + 1;
    }
    if(distance_between_prefix[A_idx][B_idx] == -1){
        if(A[A_idx] == B[B_idx]){
            distance_between_prefix[A_idx][B_idx] = ComputeDistanceBetweenPrefixes(A, A_idx-1, B, B_idx-1, distance_between_prefix_ptr);
        }else{
            int substitute_last = ComputeDistanceBetweenPrefixes(A, A_idx-1, B, B_idx-1, distance_between_prefix_ptr);
            int add_last = ComputeDistanceBetweenPrefixes(A, A_idx-1, B, B_idx, distance_between_prefix_ptr);
            int delete_last = ComputeDistanceBetweenPrefixes(A, A_idx, B, B_idx-1, distance_between_prefix_ptr);
            distance_between_prefix[A_idx][B_idx] = 1 + min(substitute_last, min(add_last, delete_last));
        }
    }
    return distance_between_prefix[A_idx][B_idx];
}

int LevenshteinDistance(const string& A, const string& B){
    vector<vector<int>> distance_between_prefixes(A.size(), vector<int>(B.size(), -1));
    return ComputeDistanceBetweenPrefixes(A, A.size()-1, B, B.size()-1, &distance_between_prefixes);
}

int main(){
    string A = "surday";
    string B = "sunday";
    cout << LevenshteinDistance(A, B)<<endl;
    return 0;
}