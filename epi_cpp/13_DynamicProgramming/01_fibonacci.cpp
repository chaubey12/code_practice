#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> cache;

int Fibonacci(int n){
    if(n <= 1){
        return n;
    }else if(!cache.count(n)){
        cache[n] = Fibonacci(n-1) + Fibonacci(n-2);
    }
    return cache[n];
}

int main(){
    int n = 10;
    cout << Fibonacci(n) << endl;
    return 0;
}