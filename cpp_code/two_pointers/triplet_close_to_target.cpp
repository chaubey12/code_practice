#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class TripletCloseToTarget{
public:
    static int searchTriplet(vector<int>& arr, int targetSum){
        int smallest_difference = numeric_limits<int>::max();
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size() - 2; i++){
            int left = i + 1, right = arr.size() - 1;
            while(left < right){
                int targetDiff = targetSum - arr[i] - arr[left] - arr[right];
                if(targetDiff == 0){
                    return targetSum;
                }
                if(abs(smallest_difference) > abs(targetDiff) ||
                (abs(targetDiff) == abs(smallest_difference) && targetDiff > smallest_difference)){
                    smallest_difference = targetDiff;
                }
                if(targetDiff > 0){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return targetSum - smallest_difference;
    }
};

int main(){
    vector<int> arr = {-1, 1, 2, 4, -2, 3, -4, -3, 0, 5};
    cout << TripletCloseToTarget::searchTriplet(arr, 15) << " is the closest sum to target"<<endl;
    return 0;
}