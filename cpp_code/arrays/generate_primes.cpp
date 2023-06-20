#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> generatePrimes(int n){
    vector<int> primes;
    deque<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int p = 2; p <= n; p++){
        if(is_prime[p]){
            primes.emplace_back(p);
            for(int j = p; j <= n; j += p){
                is_prime[j] = false;
            }
        }
    }
    return primes;
}


int main(){
    int n = 20;
    auto result = generatePrimes(n);
    for(auto num : result){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}