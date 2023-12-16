#include <iostream>
#include <vector>
#include <random>
#include <unordered_map>

using namespace std;

vector<int> RandomSubset(int n, int k){
    unordered_map<int, int> changed_elements;
    default_random_engine seed((random_device())());
    for(int i=0; i<k; ++i){
        int rand_idx = uniform_int_distribution<int>(i, n-1)(seed);
        auto ptr1 = changed_elements.find(rand_idx),
        ptr2 = changed_elements.find(i);
        if(ptr1 == changed_elements.end() && ptr2 == changed_elements.end()){
            changed_elements[rand_idx] = i;
            changed_elements[i] = rand_idx;
        }else if(ptr1 == changed_elements.end() && ptr2 != changed_elements.end()){
            changed_elements[rand_idx] = ptr2->second;
        }else if(ptr1 != changed_elements.end() && ptr2 == changed_elements.end()){
            changed_elements[i] = ptr1->second;
            ptr1->second = i;
        }else{
            int temp = ptr2->second;
            changed_elements[i] = ptr1->second;
            changed_elements[rand_idx] = temp;
        }
    }
    vector<int> result;
    for(int i=0; i < k; ++i){
        result.emplace_back(changed_elements[i]);
    }
    return result;
}

int main(){
    int n=10, k=5;
    for(int i=0; i < 10; ++i){
        auto result = RandomSubset(n,k);
        for(auto item : result){
            cout << item <<" ";
        }
        cout << endl;
    }
    return 0;
}