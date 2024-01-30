#include <iostream>
#include <vector>

using namespace std;

void DirectedCombinations(int n, int k, int offset, vector<int>* partial_combination, vector<vector<int>>* result){
    if(partial_combination->size() == k){
        result->emplace_back(*partial_combination);
        return;
    }
    const int num_remaining = k - partial_combination->size();
    for(int i=offset; i <= n && num_remaining <= n - i + 1; ++i){
        partial_combination->emplace_back(i);
        DirectedCombinations(n, k, i+1, partial_combination, result);
        partial_combination->pop_back();
    }
}

vector<vector<int>> Combinations(int n, int k){
    vector<vector<int>> result;
    DirectedCombinations(n, k, 1, new vector<int>, &result);
    return result;
}

int main(){
    auto result = Combinations(5, 3);
    for(auto res : result){
        for(auto elem : res){
            cout << elem << " "; 
        }
        cout << endl;
    }
    return 0;
}