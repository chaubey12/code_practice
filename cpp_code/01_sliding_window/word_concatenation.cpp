#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class WordConcatenation{
public:
    static vector<int> find(string& str, vector<string>& words){
        if(words.size() == 0){
            return vector<int>();
        }       
        vector<int> result;
        unordered_map<string, int> wordFrequencyMap;
        for(auto word : words){
            wordFrequencyMap[word]++;
        }
        int wordCount = words.size();
        int wordLength = words[0].length();
        for(int windowEnd = 0; windowEnd < str.length() - (wordCount*wordLength) + 1; windowEnd++){
            unordered_map<string, int> wordsSeen;
            for(int j = 0; j < wordCount; j++){
                int nextWordIndex = windowEnd + (j*wordLength);
                auto word = str.substr(nextWordIndex, wordLength);
                if(wordFrequencyMap.find(word) == wordFrequencyMap.end()){
                    break;
                }
                wordsSeen[word]++;
                if(wordsSeen[word] > wordFrequencyMap[word]){
                    break;
                }
                if((j + 1) == wordCount){
                    result.push_back(windowEnd);
                }
            }
        }
        return result;
    }
};

int main(){
    vector<string> words = {"cat", "fox"};
    string str = "catfoxcat";
    auto result = WordConcatenation::find(str, words);
    for(auto el : result){
        cout << el << " ";
    }
    cout << endl;
    return 0;
}