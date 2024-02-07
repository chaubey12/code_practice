#include <iostream>
#include <vector>

using namespace std;

int BinarySearchUnknownLength(const vector<int>& A, int k){
    int p=0;
    while(true){
        try{
            int idx = (1 << p) - 1;
            if(A.at(idx) == k){
                return idx;
            }else if(A.at(idx) > k){
                break;
            }
        }catch (const exception& e){
            break;
        }
        ++p;
    }
    int left = max(0, 1<<(p-1)), right = (1<<p)-2;
    while(left <= right){
        int mid = left + ((right - left)/2);
        try{
            if(A.at(mid) == k){
                return mid;
            }else if(A.at(mid) > k){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }catch(const exception& e){
            right = mid - 1;
        }
    }
    return -1;
}

int main(){
    return 0;
}