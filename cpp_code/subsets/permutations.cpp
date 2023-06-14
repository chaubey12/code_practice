#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Permutations{
public:
    static vector<vector<int>> find(const vector<int>& nums){
        vector<vector<int>> results;
        queue<vector<int>> permutations;
        permutations.push(vector<int>());
        for(auto currentNumber : nums){
            int n = permutations.size();
            for(int i = 0; i < n; i++){
                vector<int> oldPermutation = permutations.front();
                permutations.pop();
                for(int j = 0; j <= oldPermutation.size(); j++){
                    vector<int> newPermutation(oldPermutation);
                    newPermutation.insert(newPermutation.begin() + j, currentNumber);
                    if(newPermutation.size() == nums.size()){
                        results.push_back(newPermutation);
                    }else{
                        permutations.push(newPermutation);
                    }
                }
            }
        }
        return results;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5};
    auto result = Permutations::find(nums);
    for(auto item : result){
        for(auto elem : item){
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}