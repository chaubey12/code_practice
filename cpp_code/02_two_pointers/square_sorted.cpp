#include <iostream>
#include <vector>

using namespace std;

class SquaredSort{
public:
    static vector<int> sort(vector<int>& arr){
        int n = arr.size();
        vector<int> square_arr(n);
        int left = 0, right = n - 1;
        int highestSquareIndex = n - 1;
        while(left <= right){
            int ls = arr[left]*arr[left];
            int rs =  arr[right]*arr[right];
            if(ls > rs){
                square_arr[highestSquareIndex] = ls;
                left++;
            }else{
                square_arr[highestSquareIndex] = rs;
                right--;
            }
            highestSquareIndex--;
        } 
        return square_arr;
    }
};

int main(){
    vector<int> arr = {-5, -2, 1, 3};
    auto result = SquaredSort::sort(arr);
    for(auto el : result){
        cout << el << " ";
    }
    cout << endl;
    return 0;
}