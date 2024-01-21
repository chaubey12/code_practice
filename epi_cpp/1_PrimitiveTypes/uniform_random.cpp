#include <iostream>
#include <random>

using namespace std;

int UniformRandom(int lower_bound, int upper_bound){
    int number_of_outcomes = upper_bound - lower_bound + 1;
    int result;
    default_random_engine seed((random_device())());
    uniform_int_distribution<int> distro(0, 1);
    do{
        result = 0;
        for(int i=0; (1<<i) < number_of_outcomes; ++i){
            result = (result<<1)|distro(seed);
        }
    }while(result >= number_of_outcomes);
    return result;
}

int main(){
    int lower_bound = 3, upper_bound = 20;
    for(int i=0; i < 10; ++i){
        cout << UniformRandom(lower_bound, upper_bound) << endl;
    }
    return 0;
}