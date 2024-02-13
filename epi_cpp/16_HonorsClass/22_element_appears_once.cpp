#include <iostream>
#include <vector>
#include <array>

using namespace std;

int FindElementAppearsOnce(const vector<int>& A){
    array<int, 32> counts = {};
    for(int x : A){
        for(int i=0; i < 32; ++i){
            if(x & (1<<i)){
                ++counts[i];
            }
        }
    }
    int result=0;
    for(int i=0; i < 32; ++i){
        result |= (counts[i]%3)*(1<<i);
    }
    return result;
}

int main(){
    vector<int> A{2,2,5,2,5,5,7};
    cout << FindElementAppearsOnce(A)<<endl;
    return 0;
}