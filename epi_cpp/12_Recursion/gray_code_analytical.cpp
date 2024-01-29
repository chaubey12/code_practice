#include <iostream>
#include <vector>

using namespace std;

vector<int> GrayCode(int num_bits){
    if(num_bits == 0){
        return {0};
    }
    if(num_bits == 1){
        return {0, 1};
    }
    auto gray_code_num_bits_minus_1 = GrayCode(num_bits-1);
    int leading_bit_one = 1 <<(num_bits - 1);
    vector<int> reflection;
    for(int i = gray_code_num_bits_minus_1.size() - 1; i >= 0; --i){
        reflection.emplace_back(leading_bit_one | gray_code_num_bits_minus_1[i]);
    }
    vector<int> result = gray_code_num_bits_minus_1;
    result.insert(result.end(), reflection.begin(), reflection.end());
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