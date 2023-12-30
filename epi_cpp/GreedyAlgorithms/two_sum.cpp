#include <iostream>
#include <vector>

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

int main(){
    vector<int> A{2, 8, 9, 17, 21, 23, 25};
    int t = 45;
    if(HasTwoSum(A, t)){
        cout << "HAS TWO SUM" << endl;
    }else{
        cout << "DOESN'T HAVE TWO SUM"<<endl;
    }
    return 0;
}