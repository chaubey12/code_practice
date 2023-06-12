#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Subsets{
public:
    static vector<vector<int>> find(const vector<int>& nums){
        vector<vector<int>> subsets;
        subsets.push_back(vector<int>());
        for(int currentNum : nums){
            int n = subsets.size();
            for(int i = 0; i < n; i++){
                vector<int> set(subsets[i]);
                set.push_back(currentNum);
                subsets.push_back(set);
            }
        }
        return subsets;
    }
};

int main(){
    vector<int> arr = {1,2,3};
    auto result = Subsets::find(arr);
    for(auto item : result){
        for(auto elem : item){
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}