#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class RemoveElement{
public:
    static int remove(vector<int>& arr, int key){
        int nextElement = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] != key){
                arr[nextElement] = arr[i];
                nextElement++;
            }
        }
        return nextElement;
    }
};

int main(){
    vector<int> arr = {1, 2, 3, 1, 2, 1, 4, 8, 6, 8, 9, 1, 2, 9};
    int result = RemoveElement::remove(arr, 1);
    for(int i = 0; i < result; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}