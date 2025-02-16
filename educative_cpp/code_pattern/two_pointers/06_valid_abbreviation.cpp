#include <iostream>
#include <vector>

using namespace std;

bool ValidWordAbbreviation(const string& word, const string& abbr){
    int wordIdx=0, abbrIdx=0;
    while(abbrIdx < abbr.size()){
        if(isdigit(abbr[abbrIdx])){

        }else{
            if(wordIdx >= word.size() || word[wordIdx] != abbr[abbrIdx]){
                return false;
            }
            ++wordIdx;
            ++abbrIdx;
        }
    }
}