#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int FindKnapsack(int capacity, vector<int>& weights, vector<int>& values, int n){
    if(n == 0 || capacity == 0){
        return 0;
    }
    if(weights[n-1] <= capacity){
        return max(value[n-1] + FindKnapsack(capacity - weights[n-1], weights, values, n-1),
                   FindKnapsack(capacity, weights, values, n-1));
    }
    return FindKnapsack(capacity, weights, values, n-1);
}

int main(){

    return 0;
}