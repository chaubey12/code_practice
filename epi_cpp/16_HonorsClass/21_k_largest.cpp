#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int FindKthLargestUnknownLength(istringstream *sin, int k){
    vector<int> candidates;
    int x;
    while(*sin >> x){
        candidates.emplace_back(x);
        if(candidates.size() == 2*k - 1){
            nth_element(candidates.begin(), candidates.begin() + k - 1, candidates.end(), greater<int>());
            candidates.resize(k);
        }
    }
    nth_element(candidates.begin(), candidates.begin() + k - 1, candidates.end(), greater<int>());
    return candidates[k-1];
}

int main(){
    return 0;
}