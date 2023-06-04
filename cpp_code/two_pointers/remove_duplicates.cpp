#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class RemoveDuplicates{
public:
    static int remove(vector<int>& arr){
        sort(arr.begin(), arr.end());
        int nextNonDuplicate = 1;
        for(int i = 1; i < arr.size(); i++){
            if(arr[nextNonDuplicate - 1] != arr[i]){
                arr[nextNonDuplicate] = arr[i];
                nextNonDuplicate++;
            }
        }
        return nextNonDuplicate;
    }
};

int main(){
    vector<int> arr = {1, 2, 3, 1, 2, 1, 4, 8, 6, 8, 9, 1, 2, 9};
    int result = RemoveDuplicates::remove(arr);
    for(int i = 0; i < result; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}