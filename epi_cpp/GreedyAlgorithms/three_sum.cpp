#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool HasTwoSum(vector<int> A, int t){
    int i=0, j= A.size() - 1;
    while(i < j){
        if(A[i] + A[j] == t){
            return true;
        }else if(A[i] + A[j] < t){
            ++i;
        }else{
            --j;
        }
    }
    return false;
}

bool HasThreeSum(vector<int> A, int t){
    sort(A.begin(), A.end());
    for(int a : A){
        if(HasTwoSum(A, t - a)){
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> A{18, 19, 1, 5, 2, 8, 9, 17, 21, 23, 25};
    int t = 45;
    if(HasThreeSum(A, t)){
        cout << "HAS THREE SUM" << endl;
    }else{
        cout << "DOESN'T HAVE THREE SUM"<<endl;
    }
    return 0;
}