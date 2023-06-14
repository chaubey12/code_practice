#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class LetterCaseStringPermutations{
public:
    static vector<string> generate(const string& str){
        vector<string> result;
        result.push_back(str);
        for(int i = 0; i < str.length(); i++){
            if(isalpha(str[i])){
                int n = result.size();
                for(int j = 0; j < n; j++){
                    vector<char> chs(result[j].begin(), result[j].end());
                    if(islower(chs[i])){
                        chs[i] = toupper(chs[i]);
                    }else{
                        chs[i] = tolower(chs[i]);
                    }
                    result.push_back(string(chs.begin(), chs.end()));
                }
            }
        }
        return result;
    }
};

int main(){
    string str = "mad";
    auto res = LetterCaseStringPermutations::generate(str);
    for(auto elem : res){
        cout << elem << endl;
    }
    return 0;
}