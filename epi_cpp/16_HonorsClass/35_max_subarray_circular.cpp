#include <iostream>
#include <vector>

using namespace std;

int FindMaxSubarray(const vector<int>& A){
    int maximum_till=0, maximum=0;
    for(int a : A){
        maximum_till = max(a, a + maximum_till);
        maximum = max(maximum, maximum_till);
    }
    return maximum;
}

int FindCircularMaxSubarray(const vector<int>& A){
    vector<int> maximum_begin;
    int sum = A.front();
    maximum_begin.emplace_back(sum);
    for(int i=1; i < A.size(); ++i){
        sum += A[i];
        maximum_begin.emplace_back(max(maximum_begin.back(), sum));
    }
    vector<int> maximum_end(A.size());
    sum = 0;
    for(int i=A.size()-2; i >= 0; --i){
        sum += A[i+1];
        maximum_end[i] = max(maximum_end[i+1], sum);
    }
    int circular_max = 0;
    for(int i=0; i < A.size(); ++i){
        circular_max = max(circular_max, maximum_begin[i] + maximum_end[i]);
    }
    return circular_max;
}

int MaxSubarraySumInCircular(const vector<int>& A){
    return max(FindMaxSubarray(A), FindCircularMaxSubarray(A));
}

int main(){
    vector<int> A {904, 40, 523, 12, -335, -385, -124, 481, -31};
    cout << FindMaxSubarray(A)<<endl;
    cout << MaxSubarraySumInCircular(A)<<endl;
    return 0;
}