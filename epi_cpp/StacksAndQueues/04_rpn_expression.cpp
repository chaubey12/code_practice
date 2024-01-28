#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int Eval(const string& RPN_expression){
    stack<int> intermediate_results;
    stringstream ss(RPN_expression);
    const char kDelimiter = ',';
    string token;
    while (getline(ss, token, kDelimiter)){
        if(token == "+" || token == "-" || token == "*" || token == "/"){
            int y = intermediate_results.top();
            intermediate_results.pop();
            int x = intermediate_results.top();
            intermediate_results.pop();
            switch(token.front()){
                case '+':
                    intermediate_results.emplace(x+y);
                    break;
                case '-':
                    intermediate_results.emplace(x-y);
                    break;
                case '*':
                    intermediate_results.emplace(x*y);
                    break;
                case '/':
                    intermediate_results.emplace(x/y);
                    break;
            }
        }else{
            intermediate_results.emplace(stoi(token));
        }
    }
    
    return intermediate_results.top();
}

int main(){
    string rpn_expression = "3,4,+,2,*,1,+";
    cout << Eval(rpn_expression)<<endl;
    return 0;
}