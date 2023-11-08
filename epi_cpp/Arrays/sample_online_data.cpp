#include <iostream>
#include <vector>
#include <sstream>
#include <random>

using namespace std;


vector<int> OnlineRandomSampling(istringstream* sin, int k){
    vector<int> running_sample;
    int x;
    for(int i=0; i < k && (*sin >> x); ++i){
        running_sample.emplace_back(x);
    }
    int num_seen_so_far = k;
    default_random_engine seed((random_device())());
    while(*sin >> x){
        ++num_seen_so_far;
        int idx_to_replace = uniform_int_distribution<int>{0, num_seen_so_far-1}(seed);
        if(idx_to_replace < k){
            running_sample[idx_to_replace] = x;
        }
    }
    return running_sample;
}

int main(){
    string str = "1 2 3 5 9 4 7 8";
    istringstream mystream(str);
    int k = 4;
    auto res = OnlineRandomSampling(&mystream, k);
    for(auto re : res){            
        cout << re << " ";
    }
    cout << endl;
    return 0;
}