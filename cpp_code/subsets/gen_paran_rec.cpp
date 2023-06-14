#include <iostream>
#include <vector>
#include <string>

using namespace std;

class GenerateParantheses{
public:
    static vector<string> generate(int nums){
        vector<string> result;
        vector<char> currStr(2*nums);
        generateUtil(nums, 0, 0, 0,result, currStr);
        return result;
    }

    static void generateUtil(int nums, int open, int close, int index ,vector<string>& result, vector<char>& currString){
        if(open == nums && close == nums){
            result.push_back(string(currString.begin(), currString.end()));
            return;
        }else{
            if(open < nums){
                currString[index] = '(';
                generateUtil(nums, open + 1, close, index + 1, result, currString);
            }
            if(open > close){
                currString[index] = ')';
                generateUtil(nums, open, close + 1, index + 1, result, currString);
            }
        }
    }
};

int main(){
    int num = 5;
    auto result = GenerateParantheses::generate(num);
    for(auto item : result){
        cout << item << endl;
    }
    return 0;
}