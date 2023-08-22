#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

class FruitBasket{
public:
    static int find(string& str){
        int windowStart=0;
        int maxLength = numeric_limits<int>::min();
        unordered_map<char, int> fruitFrequencyMap;
        for(int windowEnd=0; windowEnd < str.length(); windowEnd++){
            char rightChar = str[windowEnd];
            fruitFrequencyMap[rightChar]++;
            while(fruitFrequencyMap.size() > 2){
                char leftChar = str[windowStart++];
                fruitFrequencyMap[leftChar]--;
                if(fruitFrequencyMap[leftChar] == 0){
                    fruitFrequencyMap.erase(leftChar);
                }
            }
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }
        return maxLength;
    }
};

int main(){
    string str = "ccaabbb";
    cout << FruitBasket::find(str) << endl;
    return 0;
}