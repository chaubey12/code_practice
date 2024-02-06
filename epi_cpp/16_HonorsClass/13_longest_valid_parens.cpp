#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int LongestValidParentheses(const string& s){
    int max_length = 0, end = -1;
    stack<int> left_parantheses_indices;
    for(int i=0; i < s.size(); ++i){
        if(s[i] == '('){
            left_parantheses_indices.emplace(i);
        }else if(left_parantheses_indices.empty()){
            end = i;
        }else{
            left_parantheses_indices.pop();
            int start = left_parantheses_indices.empty()
                        ? end 
                        : left_parantheses_indices.top();
            max_length = max(max_length, i - start);
        }
    }
    return max_length;
}


int main(){
    string s = "((())()(()(";
    cout << "MAX LENGTH = "<< LongestValidParentheses(s)<<endl;
    return 0;
}