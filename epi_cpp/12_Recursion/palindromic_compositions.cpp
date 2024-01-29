#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool IsPalindrome(const string& prefix){
    for(int i=0, j=prefix.size()-1; i<j; ++i, --j){
        if(prefix[i] != prefix[j]){
            return false;
        }
    }
    return true;
}

void DirectedPalindromePartitioning(const string& input, int offset, 
    vector<string>* partial_partition, vector<vector<string>>* result){
    if(offset == input.size()){
        result->emplace_back(*partial_partition);
        return;
    }
    for(int i=offset+1; i <= input.size(); ++i){
        string prefix = input.substr(offset, i - offset);
        if(IsPalindrome(prefix)){
            partial_partition->emplace_back(prefix);
            DirectedPalindromePartitioning(input, i, partial_partition, result);
            partial_partition->pop_back();
        }
    }
}

vector<vector<string>> PalindromePartitioning(const string& input){
    vector<vector<string>> result;
    DirectedPalindromePartitioning(input, 0, new vector<string>, &result);
    return result;
}

int main(){
    string input = "0204451881";
    auto results = PalindromePartitioning(input);
    for(auto result : results){
        for(auto elem : result){
            cout << elem <<" ";
        }
        cout << endl;
    }
    return 0;
}