#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <queue>

using namespace std;
struct CharWithFrequency{
    char c;
    double freq;
};

struct BinaryTreeNode{
    double aggregate_freq;
    CharWithFrequency *s;
    shared_ptr<BinaryTreeNode> left, right;
};

void AssignHuffmanCode(const shared_ptr<BinaryTreeNode>& tree, const unique_ptr<string>& code,
                       unordered_map<char, string>* huffman_encoding){
    if(tree){
        if(tree->s){
            (*huffman_encoding)[tree->s->c] = *code;
        }else{
            code->push_back('0');
            AssignHuffmanCode(tree->left, code, huffman_encoding);
            code->pop_back();
            code->push_back('1');
            AssignHuffmanCode(tree->right, code, huffman_encoding);
            code->pop_back();
        }
    }
}

unordered_map<char, string> HuffmanEncoding(vector<CharWithFrequency>* symbols){
    priority_queue<shared_ptr<BinaryTreeNode>, vector<shared_ptr<BinaryTreeNode>>,
        function<bool(shared_ptr<BinaryTreeNode>, shared_ptr<BinaryTreeNode>)>>
    candidates([](const shared_ptr<BinaryTreeNode>& lhs, const shared_ptr<BinaryTreeNode>& rhs) -> bool{
        return lhs->aggregate_freq > rhs->aggregate_freq;
    });
    for(auto& s : *symbols){
        candidates.emplace(new BinaryTreeNode{s.freq, &s, nullptr, nullptr});
    }
    while (candidates.size() > 1){
        shared_ptr<BinaryTreeNode> left = candidates.top();
        candidates.pop();
        shared_ptr<BinaryTreeNode> right = candidates.top();
        candidates.pop();
        candidates.emplace(new BinaryTreeNode{
            left->aggregate_freq + right->aggregate_freq, nullptr, left, right
        });
    }
    unordered_map<char, string> huffmn_encoding;
    AssignHuffmanCode(candidates.top(), make_unique<string>(), &huffmn_encoding);
    return huffmn_encoding;
}

int main(){
    vector<CharWithFrequency> freq_table{
        {'a', 8.17},
        {'b', 1.49},
        {'c', 2.78},
        {'d', 4.25},
        {'e', 2.78},
        {'f', 4.25},
        {'g', 12.70},
        {'h', 2.23},
        {'i', 2.02},
        {'j', 6.09},
        {'k', 6.97},
        {'l', 0.15},
        {'m', 0.77},
        {'n', 4.03},
        {'o', 2.41},
        {'p', 6.75},
        {'q', 7.51},
        {'r', 1.93},
        {'s', 0.10},
        {'t', 5.99},
        {'u', 6.33},
        {'v', 9.06},
        {'w', 2.36},
        {'x', 0.15},
        {'y', 1.97},
        {'z', 0.07}
    };
    auto huffman_codes = HuffmanEncoding(&freq_table);
    for(auto& code : huffman_codes){
        cout << code.first << ":"<<code.second<<endl;
    }
    return 0;
}