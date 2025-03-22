#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class TimeStamp{
public:
    unordered_map<string, vector<string>> valuesDict;
    unordered_map<string, vector<int>> timestampDict;
    void SetValue(string key, string value, int timestamp){
        if(valuesDict.count(key) > 0){
            if(value != valuesDict[key].back()){
                valuesDict[key].push_back(value);
                timestampDict[key].push_back(timestamp);
            }
        }else{
            valuesDict[key] = {value};
            timestampDict[key] = {timestamp};
        }
    }

    int SearchIndex(int n, const string& key, int timestamp){
        int left = 0;
        int right = n;
        int mid = 0;
        while(left < right){
            mid = (left + right) >> 1;
            if(timestampDict[key][mid] <= timestamp){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left - 1;
    }

    string GetValue(const string& key, int timestamp){
        if(valuesDict.count(key) == 0){
            return "";
        }else{
            int index = SearchIndex(timestampDict[key].size(), key, timestamp);
            if(index > -1){
                return valuesDict[key][index];
            }
        }
        return "";
    }
};