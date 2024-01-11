#include <iostream>
#include <vector>
#include <limits>
#include <numeric>
#include <random>

using namespace std;

int NonuniformRandomNumberGeneration(const vector<int>& values, const vector<double>& probabilities){
    vector<double> prefix_sum_of_probabilities;
    prefix_sum_of_probabilities.emplace_back(0.0);
    partial_sum(probabilities.cbegin(), probabilities.cend(), back_inserter(prefix_sum_of_probabilities));
    default_random_engine seed((random_device())());
    double uniform_0_1 = generate_canonical<double, numeric_limits<double>::digits>(seed);
    int interval_idx = distance(prefix_sum_of_probabilities.cbegin(), upper_bound(prefix_sum_of_probabilities.cbegin(), prefix_sum_of_probabilities.cend(), uniform_0_1)) - 1;
    return values[interval_idx];
}

int main(){
    vector<int> values = {12, 8, 9, 5, 7};
    vector<double> probabilities = {0.1, 0.2, 0.3, 0.25, 0.15};
    for(int i=0; i < 10; i++){
        cout << NonuniformRandomNumberGeneration(values, probabilities)<<endl;
    } 
    return 0;
}