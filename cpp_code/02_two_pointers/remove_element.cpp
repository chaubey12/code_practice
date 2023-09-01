#include <iostream>
#include <vector>

using namespace std;

class RemoveElement{
public:
    static int remove(vector<int>& arr, int key){
        int nextIndex = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] != key){
                arr[nextIndex] = arr[i];
                nextIndex++;
            }
        }
        return nextIndex;
    }
};

int main(){
    vector<int> arr = {3,2,6,3,10,9,3};
    int key = 3;
    int range = RemoveElement::remove(arr, key);
    for(int i = 0; i < range; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}