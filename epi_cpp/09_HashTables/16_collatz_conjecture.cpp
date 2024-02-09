#include <iostream>
#include <unordered_set>

using namespace std;

bool TestCollatzConjecture(int n){
    unordered_set<long> verified_numbers;
    for(int i=3; i <= n; i += 2){
        unordered_set<long> sequence;
        long test_i = i;
        while(test_i >= i){
            if(!sequence.emplace(test_i).second){
                return false;
            }
            if(test_i % 2){
                if(!verified_numbers.emplace(test_i).second){
                    break;
                }
                long next_test_i = 3 * test_i + 1;
                if(next_test_i <= test_i){
                    throw overflow_error("Collatz sequence overflow for " + to_string(i));
                }
                test_i = next_test_i;
            }else{
                test_i /= 2;
            }
        }
    }
    return true;
}

int main(){
    int n = 11;
    if(TestCollatzConjecture(n)){
        cout << "Collatz conjecture satisfied"<<endl;
    }else{
        cout << "Collatz conjecture not satisfied"<<endl;
    }
    return 0;
}