#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool FindSumOfThree(vector<int> nums, int target){
    sort(nums.begin(), nums.end());
    for(int i=0; i < nums.size() - 2; ++i){
        int low = i+1;
        int high = nums.size() - 1;
        while(low < high){
            int triple = nums[i] + nums[low] + nums[high];
            if(triple == target){
                return true;
            }else if(triple < target){
                low += 1;
            }else{
                high -= 1;
            }
        }
    }
    return false;
}

int main(){
    vector<int> nums {3, 7, 1, 2, 8, 4, 5};
    if(FindSumOfThree(nums, 10)){
        cout << "FOUND" << endl;
    }else{
        cout << "NOT FOUND"<<endl;
    }
    return 0;
}