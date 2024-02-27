#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;
vector<string> SearchFrequentItems(int k, istringstream *sin){
    string buf;
    unordered_map<string, int> hash;
    int n=0;
    while(*sin >> buf){
        ++hash[buf], ++n;
        if(hash.size() == k){
            auto it = hash.begin();
            while(it != hash.end()){
                if(--(it->second) == 0){
                    hash.erase(it++);
                }else{
                    ++it;
                }
            }
        }
    }
    for(auto& it : hash){
        it.second = 0;
    }
    sin->clear();
    sin->seekg(0, ios::beg);
    while(*sin >> buf){
        auto it = hash.find(buf);
        if(it != hash.end()){
            ++it->second;
        }
    }
    vector<string> ret;
    for(const auto& it : hash){
        if(it.second > static_cast<double>(n)/k){
            ret.emplace_back(it.first);
        }
    }
    return ret;
}


int main(){
    string str = "b a c a a b a a c a";
    istringstream ss(str);
    int k = 3;
    auto result = SearchFrequentItems(k, &ss);
    for(auto res : result){
        cout << res << endl;
    }
    return 0;
}