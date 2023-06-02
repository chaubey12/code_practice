#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class PairWithTargetSum{
public:
    static pair<int, int> search(vector<int>& arr, int targetSum){
        if(arr.size() <= 1){
            return make_pair(-1, -1); 
        }
        sort(arr.begin(), arr.end());
        int left = 0, right = arr.size() - 1;
        while(left < right){
            int currentSum = arr[left] + arr[right];
            if(currentSum == targetSum){
                return make_pair(left, right);
            }
            if(currentSum < targetSum){
                left++;
            }else{
                right--;
            }
        }
        return make_pair(-1, -1);
    }
};

int main(){
    vector<int> arr{5, 7, 2, 9, 11, 6};
    int targetSum=13;
    pair<int, int> result =  PairWithTargetSum::search(arr, targetSum);
    cout <<"{"<< result.first << ", "<< result.second << "}" <<endl;
    return 0;
}