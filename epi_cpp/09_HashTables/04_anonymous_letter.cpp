#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

bool IsLetterConstructibleFromMagzine(const string& letter_text, const string& magzine_text){
    unordered_map<char, int> char_frequency_for_letter;
    for(char c : letter_text){
        ++char_frequency_for_letter[c];
    }
    for(char c : magzine_text){
        auto it = char_frequency_for_letter.find(c);
        if(it != char_frequency_for_letter.cend()){
            --it->second;
            if(it->second == 0){
                char_frequency_for_letter.erase(it);
                if(char_frequency_for_letter.empty()){
                    break;
                }
            }
        }
    }
    return char_frequency_for_letter.empty();
}

int main(){
    string letter_text = "geeksforgeeks";
    string magzine_text = "gees are always standing for geeks";
    if(IsLetterConstructibleFromMagzine(letter_text, magzine_text)){
        cout << "CAN BE CONSTRUCTED"<< endl;
    }else{
        cout << "CANNOT BE CONSTRUCTED" << endl;
    }
    return 0;
}