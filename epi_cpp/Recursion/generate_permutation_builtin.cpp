#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> Permutations(vector<int> A){
    vector<vector<int>> result;
    sort(A.begin(), A.end());
    do{
        result.emplace_back(A);
    }while(next_permutation(A.begin(), A.end()));
    return result;
}

int main(){
    vector<int> A{1, 2, 3};
    auto result = Permutations(A);
    for(auto vec : result){
        for(auto item : vec){
            cout << item << " ";
        }
        cout << endl;
    }
    return 0;
}