#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <set>

using namespace std;

struct ABSqrt2{
    ABSqrt2(int a, int b) : a(a), b(b), val(a + b*sqrt(2)){}
    int a, b;
    double val;
    bool operator < (const ABSqrt2& that) const { return val < that.val; }
};

vector<ABSqrt2> GenerateFirstKABABSqrt2(int k){
    set<ABSqrt2> candidates;
    vector<ABSqrt2> result;
    candidates.emplace(0, 0);
    while(result.size() < k){
        auto next_smallest = candidates.cbegin();
        result.emplace_back(*next_smallest);
        candidates.emplace(next_smallest->a + 1, next_smallest->b);
        candidates.emplace(next_smallest->a, next_smallest->b + 1);
        candidates.erase(next_smallest);
    }
    return result;
}

int main(){
    int k = 5;
    auto result = GenerateFirstKABABSqrt2(k);
    for(auto item : result){
        cout << "a="<<item.a << ",b="<<item.b<<endl;
    }
    cout << endl;
    return 0;
}