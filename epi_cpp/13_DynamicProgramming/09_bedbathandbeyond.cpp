#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
vector<string> DecomposeIntoDictionaryWords(const string& domain, unordered_set<string>& dictionary){
    vector<int> last_length(domain.size(), -1);
    for(int i=0; i < domain.size(); ++i){
        if(dictionary.find(domain.substr(0, i+1)) != dictionary.end()){
            last_length[i] = i+1;
        }
        if(last_length[i] == -1){
            for(int j=0; j < i; ++j){
                if((last_length[j] != -1) &&(dictionary.find(domain.substr(j+1, i-j)) != dictionary.cend())){
                    last_length[i] = i-j;
                    break;
                }
            }
        }
    }
    vector<string> decompositions;
    if(last_length.back() != -1){
        int idx = domain.size()-1;
        while(idx >= 0){
            decompositions.emplace_back(
                domain.substr(idx+1-last_length[idx], last_length[idx])
            );
            idx -= last_length[idx];
        }
        reverse(decompositions.begin(), decompositions.end());
    }
    return decompositions;
}

int main(){
    string domain = "bedbathandbeyond";
    vector<string> dict{"bed", "bath", "cot", "and", "beyond", "bat", "hand"};
    unordered_set<string> dictionary(dict.begin(), dict.end());
    auto words = DecomposeIntoDictionaryWords(domain, dictionary);
    for(auto word : words){
        cout << word << endl;
    }
    return 0;
}