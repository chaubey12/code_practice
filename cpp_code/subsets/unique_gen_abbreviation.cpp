#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class AbbreviatedWord{
public:
    string str;
    int start=0;
    int count = 0;
    AbbreviatedWord(string str, int start, int count){
        this->str = str;
        this->start = start;
        this->count = count;
    }
};

class GeneralizedAbbreviation{
public:
    static vector<string> generate(const string& word){
        int wordLen = word.length();
        vector<string> result;
        queue<AbbreviatedWord> q;
        q.push({"", 0, 0});
        while(!q.empty()){
            AbbreviatedWord abWord = q.front();
            q.pop();
            if(abWord.start == wordLen){
                if(abWord.count != 0){
                    abWord.str += to_string(abWord.count);
                }
                result.push_back(abWord.str);
            }else{
                q.push({abWord.str, abWord.start + 1, abWord.count + 1});
                if(abWord.count != 0){
                    abWord.str += to_string(abWord.count);
                }
                abWord.str += word[abWord.start];
                q.push({abWord.str, abWord.start + 1, 0});
            }
        }
        return result;
    }
};

int main(){
    string name = "madhup";
    auto result = GeneralizedAbbreviation::generate(name);
    for(string ele : result){
        cout << ele << endl;
    }
    return 0;
}