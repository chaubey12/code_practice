#include <iostream>
#include <stack>

using namespace std;

bool IsWellFormed(const string& s){
    stack<char> left_chars;
    for(size_t i = 0; i < s.size(); ++i){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            left_chars.emplace(s[i]);
        }else{
            if(left_chars.empty()){
                return false;
            }
            if((s[i] == ')' && left_chars.top() != '(') ||
               (s[i] == '}' && left_chars.top() != '{') ||
               (s[i] == ']' && left_chars.top() != '[')){
                return false;
            }
            left_chars.pop();
        }
    }
    return left_chars.empty();
}

int main(){
    string parens = "[[[](({}}}))]]";
    cout << (IsWellFormed(parens) ? "YES" : "NO")<<endl; 
    return 0;
}