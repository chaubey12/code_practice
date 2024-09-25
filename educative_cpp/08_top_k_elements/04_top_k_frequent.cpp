#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Comp{
    bool operator()(pair<int, int>& p1, pair<int, int>& p2){
        return p1.second > p2.second;
    }
};

