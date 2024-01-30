#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;    

bool DiffersByOneBit(int x, int y){
    int bit_difference = x^y;
    return bit_difference && !(bit_difference & (bit_difference - 1));
}

bool DirectedGrayCode(int num_bits, unordered_set<int>* history, vector<int>* result){
    if(result->size() == (1 << num_bits)){
        return DiffersByOneBit(result->front(), result->back());
    }
    for(int i=0; i < num_bits; ++i){
        int previous_code = result->back();
        int candidate_next_code = previous_code^(1<<i);
        if(!history->count(candidate_next_code)){
            history->emplace(candidate_next_code);
            result->emplace_back(candidate_next_code);
            if(DirectedGrayCode(num_bits, history, result)){
                return true;
            }
            history->erase(candidate_next_code);
            result->pop_back();
        }
    }
    return false;
}

vector<int> GrayCode(int num_bits){
    vector<int> result({0});
    DirectedGrayCode(num_bits, new unordered_set<int>({0}), &result);
    return result;
}

int main(){
    auto result = GrayCode(4);
    for(auto item : result){
        cout << item<<" ";
    }
    cout << endl;
    return 0;
}