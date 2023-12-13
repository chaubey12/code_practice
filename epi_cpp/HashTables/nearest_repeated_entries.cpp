#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <limits>

using namespace std;

int FindNearestRepetition(const vector<string>& paragraph){
    unordered_map<string, int> word_to_latest_index;
    int nearest_repeated_distance = numeric_limits<int>::max();
    for(int i=0; i < paragraph.size(); ++i){
        auto latest_equal_word = word_to_latest_index.find(paragraph[i]);
        if(latest_equal_word != word_to_latest_index.end()){
            nearest_repeated_distance = min(nearest_repeated_distance, i - latest_equal_word->second);
        }
        word_to_latest_index[paragraph[i]] = i;
    }
    return nearest_repeated_distance;
}

int main(){
    vector<string> paragraph = {"all","work","and","no","play","makes","for","no","work","no","fun","and","no","results"};
    cout << "Nearest word distance is :" << FindNearestRepetition(paragraph)<<endl;
    return 0;
}