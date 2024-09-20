#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

string FractionToDecimal(int numerator, int denominator){
    string result;
    unordered_map<long long, int> remainderMap;
    if(numerator == 0){
        return "0";
    }
    if((numerator < 0) ^ (denominator < 0)){
        result += "-";
        numerator = abs(static_cast<long long>(numerator));
        denominator = abs(denominator);
    }
    long long quotient = numerator / denominator;
    long long remainder = (numerator%denominator)*10;
    result += to_string(quotient);
    if(remainder == 0){
        return result;
    }else{
        result += ".";
        while(remainder != 0){
            auto it = remainderMap.find(remainder);
            if(it != remainderMap.end()){
                int beginning = it->second;
                string left = result.substr(0, beginning);
                string right = result.substr(beginning, result.length());
                result = left + "(" + right + ")";
                return result;
            }else{
                remainderMap.insert({remainder, result.length()});
                quotient = remainder / denominator;
                result += to_string(static_cast<int>(quotient));
                remainder = (remainder % denominator) * 10;
            }
        }
    }
    return result;
}

int main(){
    vector<vector<int>> inputs = {{0, 4}, {4, 2}, {5, 333}, {2, 3}, {47, 18}, {93, 7}, {-5, 333}, {47, -18}, {-4, -2}};
    for(auto input : inputs){
        cout << FractionToDecimal(input[0], input[1])<<endl;
    }
    return 0;
}