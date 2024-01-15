#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int TransformString(unordered_set<string> D, const string& s, const string& t){
    struct StringWithDistance{
        string candidate_string;
        int distance;
    };
    queue<StringWithDistance> q;
    D.erase(s);
    cout << s << "->";
    q.emplace(StringWithDistance{s, 0});
    while(!q.empty()){
        StringWithDistance f(q.front());
        if(f.candidate_string == t){
            return f.distance;
        }
        string str = f.candidate_string;
        for(int i=0; i < str.size(); ++i){
            for(int j=0; j < 26; ++j){
                str[i] = 'a' + j;
                auto it = D.find(str);
                if(it != D.end()){
                    D.erase(it);
                    q.emplace(StringWithDistance{str, f.distance + 1});
                }
            }
            str[i] = f.candidate_string[i];
        }
        q.pop();
    }
    return -1;
}

int main(){
    unordered_set<string> D{"bat", "cot", "dog", "dag", "dot", "cat"};
    string s = "cat";
    string t = "dog";
    cout << TransformString(D, s, t) << " changes to "<<s<< " to "<<t<<endl;
    return 0;
}