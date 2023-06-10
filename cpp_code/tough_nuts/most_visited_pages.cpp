#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <utility>

using namespace std;

class MostVisitedPages{
public:
    struct pagePairCompare{
        bool operator()(const pair<int, char>& a, const pair<char, int>& b){
            return a.second > b.second;
        }
    };
    static vector<pair<int, char>> kMostVisitedPage(vector<pair<char, int>> pages, int k){
        map<int, char> pageVisitMap;
        vector<pair<int, char>> result;
        for(auto item : pages){
            pageVisitMap[item.second] = item.first;
        }
        for(auto itr = pageVisitMap.rbegin(); itr != pageVisitMap.rend() && k > 0; ++itr, --k){
            result.push_back(*itr);
        }
        return result;
    }
};

int main(){
    vector<pair<char, int>> source;
    source.push_back(make_pair('a', 5));
    source.push_back(make_pair('b', 3));
    source.push_back(make_pair('c', 8));
    source.push_back(make_pair('d', 2));
    source.push_back(make_pair('e', 11));
    source.push_back(make_pair('f', 1));
    auto result = MostVisitedPages::kMostVisitedPage(source, 3);
    for(auto item : result){
        cout << item.first << " " << item.second << endl;
    }
    return 0;
}