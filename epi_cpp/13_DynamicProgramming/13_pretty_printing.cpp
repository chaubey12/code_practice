#include <iostream>
#include <vector>
#include <limits>
#include <string>

using namespace std;

int MinimumMessiness(const vector<string>& words, int line_length){
    vector<int> minimum_messiness(words.size(), numeric_limits<int>::max());
    int num_remaining_blanks = line_length - words[0].size();
    minimum_messiness[0] = num_remaining_blanks * num_remaining_blanks;
    for(int i=1; i < words.size(); ++i){
        num_remaining_blanks = line_length - words[i].size();
        minimum_messiness[i] = minimum_messiness[i-1] + num_remaining_blanks * num_remaining_blanks;
        for(int j = i-1; j >= 0; --j){
            num_remaining_blanks -= (words[j].size() + 1);
            if(num_remaining_blanks < 0){
                break;
            }
            int first_j_messiness = j-1 < 0 ? 0 : minimum_messiness[j-1];
            int current_line_messiness = num_remaining_blanks*num_remaining_blanks;
            minimum_messiness[i] = min(minimum_messiness[i], first_j_messiness + current_line_messiness);
        }
    }
    return minimum_messiness.back();
}

int main(){
    vector<string> words;
    words.emplace_back("I have inserted a large number of");
    words.emplace_back("new examples from the papers for the");
    words.emplace_back("Mathematical Tripos during the last");
    words.emplace_back("twenty years, which should be useful");
    words.emplace_back("to Cambridge students.");
    cout << MinimumMessiness(words, 36) << endl;
    return 0;
}