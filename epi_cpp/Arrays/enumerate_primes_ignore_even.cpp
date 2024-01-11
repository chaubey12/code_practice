#include <iostream>
#include <vector>
#include <cmath>
#include <deque>

using namespace std;

vector<int> GeneratePrimes(int n){
    const int size = floor(0.5*(n-3)) + 1;
    vector<int> primes;
    primes.emplace_back(2);
    deque<bool> is_prime(size, true);
    for(int i=0; i < size; ++i){
        if(is_prime[i]){
            int p = (i*2) + 3;
            primes.emplace_back(p);
            for(long j = static_cast<long>(i)*static_cast<long>(i)*2 + 6*i + 3; j < size; j += p){
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

int main(){
    vector<int> primes = GeneratePrimes(100);
    for(auto elem : primes){
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}