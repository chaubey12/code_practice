#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class RandomSet{
    unordered_map<int, int> dict;
    vector<int> list;
public:
    RandomSet(){
    }
    
    bool insert(int prod){
        if(dict.find(prod) != dict.end()){
            return false;
        }
        dict[prod] = list.size();
        list.push_back(prod);
        return true;
    }

    bool remove(int prod){
        if(dict.find(prod) == dict.end()){
            return false;
        }
        int last = list[list.size() - 1];
        int index = dict[prod];
        list[index] = last;
        dict[last] = index;
        list.pop_back();
        dict.erase(prod);
        return true;
    }

    int getRandom(){
        return list[rand() % list.size()];
    }
};