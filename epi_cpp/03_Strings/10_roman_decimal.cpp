#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int RomanToDecimal(const string& s){
    unordered_map<char, int> T ={{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000} };
    int sum = T[s.back()];
    for(int i=s.length() - 2; i >= 0; --i){
        if(T[s[i]] < T[s[i+1]]){
            sum -= T[s[i]];
        }else{
            sum += T[s[i]];
        }
    }
    return sum;
}

int main(){
    cout << RomanToDecimal("LIX")<<endl;
    return 0;
}