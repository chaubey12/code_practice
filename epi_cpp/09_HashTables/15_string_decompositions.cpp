#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

bool MatchAllWordsInDict(const string& s, const unordered_map<string, int>& word_to_freq, 
                         int start, int num_words, int unit_size){
    unordered_map<string, int> curr_string_to_freq;
    for(int i=0; i < num_words; ++i){
        string curr_word = s.substr(start + i*unit_size, unit_size);
        auto iter = word_to_freq.find(curr_word);
        if(iter == word_to_freq.end()){
            return false;
        }
        ++curr_string_to_freq[curr_word];
        if(curr_string_to_freq[curr_word] > iter->second){
            return false;
        }
    }
    return true;
}

vector<int> FindAllSubstrings(const string& s, const vector<string>& words){
    unordered_map<string, int> word_to_freq;
    for(const string& word : words){
        ++word_to_freq[word];
    }
    int unit_size = words.front().size();
    vector<int> result;
    for(int i=0; i + unit_size*words.size() <= s.size(); ++i){
        if(MatchAllWordsInDict(s, word_to_freq, i, words.size(), unit_size)){
            result.emplace_back(i);
        }
    }
    return result;
}

int main(){
    string s = "amanaplanacanal";
    vector<string> words{"can", "apl", "ana"};
    vector<int> result = FindAllSubstrings(s, words);
    for(auto el : result){
        cout << el << " ";
    }
    cout << endl;
    return 0;
}