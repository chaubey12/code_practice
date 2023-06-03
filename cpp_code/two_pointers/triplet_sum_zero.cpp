#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TripletSumZero{
public:
    static vector<vector<int>> searchTriplet(vector<int>& arr){
        vector<vector<int>> triplets;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size() - 2; i++){
            if(i > 0 && arr[i-1] == arr[i]){
                continue;
            }
            searchPairs(arr, -arr[i], i, triplets);
        }
        return triplets;
    }
private:
    static void searchPairs(vector<int>& arr, int target, int first, vector<vector<int>>& triplets){
        int left = first + 1;
        int right = arr.size() - 1;
        while(left < right){
            int sum = arr[left] + arr[right];
            if(sum == target){
                triplets.push_back({arr[first], arr[left], arr[right]});
                left++, right--;
                while(left < right && arr[left] == arr[left-1]){
                    left++;
                }
                while(left < right && arr[right] == arr[right+1]){
                    right--;
                }
            }else if(sum < target){
                left++;
            }else{
                right--;
            }
        }
    }
};

int main(){
    vector<int> arr = {-1, 1, 2, 4, -2, 3, -4, -3, 0, 5};
    auto result = TripletSumZero::searchTriplet(arr);
    for(auto& item : result){
        for(auto elem : item){
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}