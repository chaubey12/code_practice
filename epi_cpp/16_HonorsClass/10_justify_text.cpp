#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string JoinALineWithSpace(const vector<string>& words, size_t start, size_t end, size_t num_spaces){
    size_t num_words_curr_line = end - start + 1;
    string line;
    for(size_t i = start; i < end; ++i){
        line += words[i];
        --num_words_curr_line;
        size_t num_curr_space = ceil(static_cast<double>(num_spaces)/num_words_curr_line);
        line.append(num_curr_space, ' ');
        num_spaces -= num_curr_space;
    }
    line += words[end];
    line.append(num_spaces, ' ');
    return line;
}

vector<string> JustifyText(const vector<string>& words, size_t L){
    size_t curr_line_start=0, num_words_curr_line=0, curr_line_length=0;
    vector<string> result;
    for(size_t i=0; i < words.size(); ++i){
        ++num_words_curr_line;
        size_t lookahead_line_length = curr_line_length + words[i].size() + (num_words_curr_line - 1);
        if(lookahead_line_length == L){
            result.emplace_back(JoinALineWithSpace(words, curr_line_start, i, i - curr_line_start));
            curr_line_start = i+1;
            num_words_curr_line = 0;
            curr_line_length = 0;
        }else if(lookahead_line_length > L){
            result.emplace_back(JoinALineWithSpace(words, curr_line_start, i-1, L - curr_line_length));
            curr_line_start = i;
            num_words_curr_line = 1;
            curr_line_length = words[i].size();
        }else{
            curr_line_length += words[i].size();
        }
    }
    if(num_words_curr_line > 0){
        string line = JoinALineWithSpace(words, curr_line_start, words.size() - 1, num_words_curr_line - 1);
        line.append(L - curr_line_length - (num_words_curr_line - 1), ' ');
        result.emplace_back(line);
    }
    return result;
}

int main(){
    vector<string> words {"The", "quick", "brown", "fox", "jumped", "over", "the", "lazy", "dogs."};
    int L = 11;
    auto result = JustifyText(words, L);
    for(auto sentence : result){
        cout << sentence << endl;
    }
    return 0;
}