#include <iostream>
#include <vector>

using namespace std;

void DirectedGenerateBalancedParantheses(int num_left_parens, int num_right_parens, const string& valid_prefix, vector<string>* result){
    if(!num_left_parens && !num_right_parens){
        result->emplace_back(valid_prefix);
        return;
    }
    if(num_left_parens > 0){
        DirectedGenerateBalancedParantheses(num_left_parens - 1, num_right_parens, valid_prefix + '(', result);
    }
    if(num_left_parens < num_right_parens){
        DirectedGenerateBalancedParantheses(num_left_parens, num_right_parens - 1, valid_prefix + ')', result);
    }
}

vector<string> GenerateBalancedParantheses(int num_pairs){
    vector<string> result;
    DirectedGenerateBalancedParantheses(num_pairs, num_pairs, "", &result);
    return result;
}

int main(){
    auto result = GenerateBalancedParantheses(4);
    for(auto res : result){
        cout << res << endl;
    }
    return 0;
}