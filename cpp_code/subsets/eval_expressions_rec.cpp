#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class EvaluateExpression{
private:
    static unordered_map<string, vector<int>> cache;
public:
    static vector<int> diffWaysToEvaluateExpression(const string& input){
        if(cache.find(input) != cache.end()){
            return cache[input];
        }
        vector<int> result;
        if(input.find("+") == string::npos && input.find("-") == string::npos && input.find("*") == string::npos){
            result.push_back(stoi(input));
        }else{
            for(int i = 0; i < input.length(); i++){
                char ch = input[i];
                if(!isdigit(ch)){
                    vector<int> leftResults = diffWaysToEvaluateExpression(input.substr(0, i));
                    vector<int> rightResults = diffWaysToEvaluateExpression(input.substr(i+1));
                    for(auto left : leftResults){
                        for(auto right : rightResults){
                            if(ch == '+'){
                                result.push_back(left + right);
                            }else if(ch == '-'){
                                result.push_back(left - right);
                            }else if(ch == '*'){
                                result.push_back(left * right);
                            }
                        }
                    }
                }
            }
        }
        cache[input] = result;
        return result;
    }
};