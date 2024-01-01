#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct ABSqrt2{
    ABSqrt2(int a, int b): a(a), b(b), val(a + b*sqrt(2)){}
    bool operator < (const ABSqrt2& that) const { return val < that.val; }
    int a, b;
    double val;
};

vector<ABSqrt2> GenerateFirstKABSqrt2(int k){
    vector<ABSqrt2> result;
    result.emplace_back(0, 0);
    int i=0, j=0;
    for(int n=1; n < k;++n){
        ABSqrt2 result_i_plus_1(result[i].a + 1, result[i].b);
        ABSqrt2 result_j_plus_sqrt2(result[j].a, result[j].b + 1);
        result.emplace_back(min(result_i_plus_1, result_j_plus_sqrt2));
        if(result_i_plus_1.val == result.back().val){
            ++i;
        }
        if(result_j_plus_sqrt2.val ==  result.back().val){
            ++j;
        }
    }
    return result;
}

int main(){
    int k = 6;
    auto result= GenerateFirstKABSqrt2(k);
       for(auto item : result){
        cout << "a="<<item.a << ",b="<<item.b<<endl;
    }
    cout << endl;
    return 0;
}