#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool IsTargetSumOfThreePresent(vector<int>& nums, int target){
    sort(nums.begin(), nums.end());
    for(int i=0; i < nums.size() - 2; ++i){
        int left = i+1, right = nums.size() - 1;
        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == target){
                return true;
            }else if(sum < target){
                ++left;
            }else{
                --right;
            }
        }
    }
    return false;
}

int main(){
    vector<std::vector<int>> numsLists = {
        {3, 7, 1, 2, 8, 4, 5},
        {-1, 2, 1, -4, 5, -3},
        {2, 3, 4, 1, 7, 9},
        {1, -1, 0},
        {2, 4, 2, 7, 6, 3, 1}};
    vector<int> testList = {10, 7, 20, -1, 8};
    int i=0;
    for(auto numList : numsLists){
        if(IsTargetSumOfThreePresent(numList, testList[i++])){
            cout << "PRESENT"<<endl;
        }else{
            cout << "ABSENT"<<endl;
        }
    }
    return 0;
}