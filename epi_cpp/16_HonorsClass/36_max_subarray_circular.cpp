#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int FindOptimumSubarrayUsingComp(const vector<int>& A, const int& (*comp)(const int&, const int&)){
    int till=0, overall=0;
    for(int a : A){
        till = comp(a, a + till);
        overall = comp(overall, till);
    }
    return overall;
}

int MaxSubarraySumInCircular(const vector<int>& A){
    return max(FindOptimumSubarrayUsingComp(A, max),
               accumulate(A.cbegin(), A.cend(), 0) - 
               FindOptimumSubarrayUsingComp(A, min));
}

int main(){
    vector<int> A {904, 40, 523, 12, -335, -385, -124, 481, -31};
    cout << MaxSubarraySumInCircular(A)<<endl;
    return 0;
}