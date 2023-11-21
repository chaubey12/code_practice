#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> GeneratePrimes(int n){
    vector<int> primes;
    deque<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int p=2; p<n; ++p){
        if(is_prime[p]){
            primes.push_back(p);
            for(int j=p; j <= n; j+= p){
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

int main(){
    int n = 32;
    auto result = GeneratePrimes(n);
    for(auto i : result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}