#include <iostream>
#include <vector>

using namespace std;

bool IsMatchHere(const string& regex, int regex_offset, const string& s, int s_offset){
    if(regex_offset == regex.size()){
        return true;
    }
    if(regex_offset == regex.size() - 1 && 
       regex[regex_offset] == '$'){
        return s_offset == s.size();
    }
    if(regex.size() - regex_offset >= 2 && regex[regex_offset + 1] == '*'){
        for(int i=s_offset+1; i < s.size() && (regex[regex_offset] == '.' || regex[regex_offset] == s[i-1]); ++i){
            if(IsMatchHere(regex, regex_offset+2, s, i)){
                return true;
            }
        }
        return IsMatchHere(regex, regex_offset + 2, s, s_offset);
    }
    return s_offset < s.size() && 
           (regex[regex_offset] == '.' || regex[regex_offset] == s[s_offset]) &&
           IsMatchHere(regex, regex_offset + 1, s, s_offset + 1);
}

bool IsMatch(const string& regex, const string& s){
    if(regex.front() == '^'){
        return IsMatchHere(regex, 1, s, 0);
    }
    for(int i=0; i < s.size(); ++i){
        if(IsMatchHere(regex, 0, s, i)){
            return true;
        }
    }
    return false;
}

int main(){
    return 0;
}