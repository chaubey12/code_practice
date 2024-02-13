#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Trie{
private:
    struct TrieNode{
        bool isString = false;
        unordered_map<char, unique_ptr<TrieNode>> leaves;
    };
    unique_ptr<TrieNode> root_ = make_unique<TrieNode>(TrieNode());
public:
    bool Insert(const string& s){
        auto* p = root_.get();
        for(char c : s){
            if(p->leaves.find(c) == p->leaves.cend()){
                p->leaves[c] = make_unique<TrieNode>(TrieNode());
            }
            p = p->leaves[c].get();
        }
        if(p->isString){
            return false;
        }
        p->isString = true;
        return true;
    }
    string GetShortedtUniquePrefix(const string& s){
        auto* p = root_.get();
        string prefix;
        for(char c : s){
            prefix += c;
            if(p->leaves.find(c)==p->leaves.cend()){
                return prefix;
            }
            p = p->leaves[c].get();
        }
        return {};
    }
};

string FindShortestPrefix(const string& s, const unordered_set<string>& D){
    Trie T;
    for(const string& word : D){
        T.Insert(word);
    }
    return T.GetShortedtUniquePrefix(s);
}

int main(){
    unordered_set<string> D{"dog","be","cut"};
    string s = "cat";
    cout << FindShortestPrefix(s, D)<<endl;
    return 0;
}