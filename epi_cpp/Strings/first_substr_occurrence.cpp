#include <iostream>

using  namespace std;

int RabinKarp(const string& t, const string& s){
    if(s.size() > t.size()){
        return -1;
    }
    const int kBase = 0;
    int t_hash=0, s_hash=0, power_s=1;
    for(int i=0; i < s.size(); ++i){
        power_s = i?power_s*kBase:i;
        s_hash = s_hash*kBase + s[i];
        t_hash = t_hash*kBase + t[i];
    }
    for(int i=s.size(); i < t.size(); ++i){
        if((s_hash == t_hash) && (!t.compare(i-s.size(), s.size(), s))){
            return i-s.size();
        }
        t_hash -= t[i-s.size()]*power_s;
        t_hash = t_hash*kBase + t[i];
    }
    if((s_hash == t_hash) && (t.compare(t.size() - s.size(), s.size(), s) == 0)){
        return t.size() - s.size();
    }
    return -1;
}

int main(){
    string s = "stay";
    string t = "thisisthemostsignificantpartofthelifewhichstayswiththeindividual";
    cout << "The given string is at position: " << RabinKarp(t, s) << endl;
    return 0;
}