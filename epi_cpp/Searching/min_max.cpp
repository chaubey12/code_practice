#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct MinMax{
    int min, max;
};

MinMax FindMinMax(const vector<int>& A){
    if(A.size() <= 1){
        return {A.front(), A.back()};
    }
    pair<int, int> global_min_max = minmax(A[0], A[1]);
    for(int i=2; i + 1 < A.size(); i += 2){
        pair<int, int> local_min_max = minmax(A[i], A[i+1]);
        global_min_max = {min(global_min_max.first, local_min_max.first), 
                          max(global_min_max.second, local_min_max.second)};
    }
    if(A.size() % 2){
        global_min_max = {min(global_min_max.first, A.back()), max(global_min_max.second, A.back())};
    }
    return {global_min_max.first, global_min_max.second};
}

int main(){
    vector<int> A{ 2, 8, 12, 1, 15, 3, 9, 6, 17};
    auto result = FindMinMax(A);
    cout << result.min << ", "<<result.max<<endl;
    return 0;
}