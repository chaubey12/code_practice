#include <iostream>
#include <string>

using namespace std;

int RabinKarp(const string& s, const string& t){
    if(s.size() > t.size()){
        return -1;
    }
    const int kBase = 26;
    int t_hash = 0, s_hash = 0;
    int power_s = 1;
    for(int i=0; i < s.size(); ++i){
        power_s = i ? power_s*kBase : 1;
        t_hash = t_hash*kBase + t[i];
        s_hash = s_hash*kBase + s[i];
    }
    for(int i = s.size(); i < t.size(); ++i){
        if(t_hash == s_hash && !t.compare(i-s.size(), s.size(), s)){
            return i - s.size();
        }
        t_hash -= t[i - s.size()]*power_s;
        t_hash = t_hash*kBase + t[i];
    }
    if(t_hash == s_hash && t.compare(t.size() - s.size(), s.size(), s) == 0){
        return t.size() - s.size();
    }
    return -1;
}

int main(){
    string s = "CGC";
    string t = "GACGCCCA";
    cout << RabinKarp(s, t) << endl;
    return 0;
}