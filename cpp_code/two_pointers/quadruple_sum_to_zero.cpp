#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class QuadrupleSumToZero{
public:
    static vector<vector<int>> searchQuadruplets(vector<int>& arr, int target){
        vector<vector<int>> quadruplets;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size() - 3; i++){
            if(i > 0 && arr[i] == arr[i-1]){
                continue;
            }
            for(int j = i+1; j < arr.size() - 2; j++){
                if(j > i+1 && arr[j] == arr[j-1]){
                    continue;
                }
                searchPairs(arr, target, i, j, quadruplets);
            }
        }
        return quadruplets;
    }
private:
    static void searchPairs(const vector<int>& arr, int targetSum, int first, int second, vector<vector<int>>& quadruplets){
        int left = second + 1;
        int right = arr.size() - 1;
        while(left < right){
            int sum = arr[first] + arr[second] + arr[left] + arr[right];
            if(sum == targetSum){
                quadruplets.push_back({arr[first], arr[second], arr[left], arr[right]});
                left++;
                right--;
                while(left < right && arr[left] == arr[left-1]){
                    left++;
                }
                while(left < right && arr[right] == arr[right+1]){
                    right--;
                }
            }else if(sum < targetSum){
                left++;
            }else{
                right--;
            }
        }
    }
};

int main(){
    vector<int> arr={2, 3, -1, 4, -2, 5, 0, 6, -4, -3};
    auto quad = QuadrupleSumToZero::searchQuadruplets(arr, 0);
    for(auto item : quad){
        for(auto elem : item){
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}