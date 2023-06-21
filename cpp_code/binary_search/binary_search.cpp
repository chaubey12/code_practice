#include <iostream>
#include <vector>

using namespace std;

class BinarySearch{
public:
    static int search(const vector<int>& arr, int key){
        int start = 0, end = arr.size() - 1;
        bool isAscending = arr[start] < arr[end];
        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] == key){
                return mid;
            }
            if(isAscending){
                if(key < arr[mid]){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }else{
                if(key > arr[mid]){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }
        }   
        return -1;
    }
};

int main(){
    vector<int> descending = {19, 13, 10, 8, 5, 3, 1};
    vector<int> ascending = {19, 29, 110, 180, 195, 243, 341};
    int keyA = 3;
    int keyB = 110;
    cout << BinarySearch::search(descending, keyA) << endl;
    cout << BinarySearch::search(ascending, keyB) << endl;
    return 0;
}