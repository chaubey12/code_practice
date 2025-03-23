#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

typedef list<pair<int, int>> KeyValuePairLL;

class LRUCache{
    size_t cacheCapacity;
    unordered_map<int, KeyValuePairLL::iterator> cacheMap;
    KeyValuePairLL cacheList;
public:
    LRUCache(size_t size) : cacheCapacity(size) {}
    int Get(int key){
        auto foundIter = cacheMap.find(key);
        if(foundIter == cacheMap.end()){
            return -1;
        }
        auto listIterator = foundIter->second;
        cacheList.splice(cacheList.begin(), cacheList, listIterator);
        return listIterator->second;
    }

    void Set(int key, int value){
        auto foundIter = cacheMap.find(key);
        if(foundIter != cacheMap.end()){
            auto listIterator = foundIter->second;
            cacheList.splice(cacheList.begin(), cacheList, listIterator);
            listIterator->second = value;
            return;
        }
        if(cacheMap.size() == cacheCapacity){
            int key = cacheList.back().first;
            cacheList.pop_back();
            cacheMap.erase(key);
        }
        cacheList.emplace_front(key, value);
        cacheMap[key] = cacheList.begin();
    }
};