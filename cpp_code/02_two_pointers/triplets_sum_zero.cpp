#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TripletsSum{
public:
    static vector<vector<int>> find(vector<int>& arr){
        vector<vector<int>> triplets;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++){
            if(i > 0 && arr[i] == arr[i-1]){
                continue;
            }
            searchPair(arr, -arr[i], i + 1, triplets);
        }
        return triplets;
    }
private:
    static void searchPair(const vector<int>& arr, int target, int start, vector<vector<int>>& triplets){
        int end = arr.size() - 1;
        while(start < end){
            int currentSum = arr[start] + arr[end];
            if(currentSum == target){
                triplets.push_back({-target, arr[start], arr[end]});
                start++;
                end--;
                while(start < end && arr[start] == arr[start-1]){
                    start++;
                }
                while(start < end && arr[end] == arr[end+1]){
                    end--;
                }
            }else if(target > currentSum){
                start++;
            }else{
                end--;
            }
        }
    }
};

int main(){
    vector<int> arr{-3, 0, 1, 2, -1, 1, -2};
    auto result = TripletsSum::find(arr);
    for(auto entries : result){
        for(auto elem : entries){
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}