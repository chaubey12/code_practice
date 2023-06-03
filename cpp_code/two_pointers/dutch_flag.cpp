#include <iostream>
#include <vector>

using namespace std;

class DutchFlag{
public:
    static void sort(vector<int>& arr){
        int left = 0;
        int right = arr.size() - 1;
        int i = 0;
        while(left <= right){
            if(arr[left] == 0){
                swap(arr, i, left);
                i++;
                left++;
            }else if(arr[left] == 1){
                left++;
            }else{
                swap(arr, left, right);
                right--;
            }
        }
    }
private:
    static void swap(vector<int>& arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
};

int main(){
    vector<int> arr = {0, 0, 1, 0, 2, 1, 0, 0, 2, 2, 1, 0, 1, 0, 0, 1, 1, 2, 1};
    DutchFlag::sort(arr);
    for(auto elem: arr){
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}