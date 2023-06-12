#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

class EvaluateExpression{
public:
    static vector<int> diffWaysToEvalExpression(const string& input){
        vector<int> result;
        if(input.find("+") == string::npos && input.find("-") == string::npos
        && input.find("*") == string::npos){
            result.push_back(stoi(input));
        }else{
            for(int i = 0; i < input.length(); i++){
                char chr = input[i];
                if(!isdigit(chr)){
                    vector<int> leftResult = diffWaysToEvalExpression(input.substr(0, i));
                    vector<int> rightResult = diffWaysToEvalExpression(input.substr(i+1));
                    for(auto part1 : leftResult){
                        for(auto part2 : rightResult){
                            if(chr == '+'){
                                result.push_back(part1 + part2);
                            }else if(chr == '-'){
                                result.push_back(part1 - part2);
                            }else{
                                result.push_back(part1 * part2);
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};

int main(){
    string str = "1+2-3*5";
    vector<int> result = EvaluateExpression::diffWaysToEvalExpression(str);
    for(auto item : result){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}