#include <iostream>
#include <vector>

using namespace std;

class RemoveDuplicates{
public:
    static int remove(vector<int>& arr){
        int nextNonDuplicate = 1;
        for(int i=1; i < arr.size(); i++){
            if(arr[nextNonDuplicate-1] != arr[i]){
                arr[nextNonDuplicate] = arr[i];
                nextNonDuplicate++;
            }
        }
        return nextNonDuplicate;
    }
};

int main(){
    vector<int> arr = {2, 3, 3, 3, 6, 9, 9};
    cout << RemoveDuplicates::remove(arr) << endl;
    return 0;
}