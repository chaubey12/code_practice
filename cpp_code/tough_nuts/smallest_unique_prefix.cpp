#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>


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

    string GetSmallestUniquePrefix(const string& s){
        auto* p = root_.get();
        string prefix = "";
        for(char c : s){
            prefix += c;
            if(p->leaves.find(c) == p->leaves.cend()){
                return prefix;
            }
            p = p->leaves[c].get();
        }
        return {};
    }
};

string findSmallestUniquePrefix(const string& s, unordered_set<string>& dict){
    auto T = Trie();
    for(auto word : dict){
        T.Insert(word);
    }
    string prefix = T.GetSmallestUniquePrefix(s);
    return prefix;
}

int main(){
    string dict[] = {"cat", "car", "cash", "dog"};
    string word = "card";
    unordered_set<string>dict_set;
    for(auto word : dict){
        dict_set.insert(word);
    }
    cout << findSmallestUniquePrefix(word, dict_set) << " is the smallest unique prefix."<<endl;
    return 0;
}