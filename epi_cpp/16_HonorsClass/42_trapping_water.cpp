#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int CalculateTrappingWater(const vector<int> &A){
    if(A.empty()){
        return 0;
    }
    int max_h = distance(A.cbegin(), max_element(A.cbegin(), A.cend()));
    int sum = 0, left = A.front();
    for(int i=1; i < max_h; ++i){
        if(A[i] >= left){
            left = A[i];
        }else{
            sum += left - A[i];
        }
    }

    int right = A.back();
    for(int i=A.size()-2; i > max_h; --i){
        if(A[i] >= right){
            right = A[i];
        }else{
            sum += right - A[i];
        }
    }
    return sum;
}

int main(){
    vector<int> heights{0, 1, 2, 1, 3, 4, 4, 5, 1, 2, 0, 3};
    cout <<"Total trapped water: " <<CalculateTrappingWater(heights) <<endl;
    return 0;
}