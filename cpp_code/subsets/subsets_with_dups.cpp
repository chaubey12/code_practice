#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SubsetsWithDups{
public:
    static vector<vector<int>> find(vector<int>& nums){
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;
        subsets.push_back(vector<int>());
        int startIndex = 0, endIndex = 0;
        for(int i = 0; i < nums.size(); i++){
            startIndex = 0;
            if(i > 0 && nums[i] == nums[i-1]){
                startIndex = endIndex + 1;
            }
            endIndex = subsets.size() - 1;
            for(int j = startIndex; j <= endIndex; j++){
                vector<int> set(subsets[j]);
                set.push_back(nums[i]);
                subsets.push_back(set);
            }
        }
        return subsets;
    }
};


int main(){
    vector<int> arr = {1, 2, 2, 3, 3, 4};
    auto result = SubsetsWithDups::find(arr);
    for(auto item : result){
        for(auto elem : item){
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}