#include <iostream>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

class LFUCache{
private:
    int capacity, minFreq;
    unordered_map<int, pair<int, int>> keyToValueFreq;
    map<int, set<int>> freqToKeys;
public:
    LFUCache(int capacity): capacity(capacity), minFreq(0) {}
    int get(int key){
        if(keyToValueFreq.find(key) == keyToValueFreq.end()){
            return -1;
        }
        int value = keyToValueFreq[key].first;
        int freq = keyToValueFreq[key].second;

        freqToKeys[freq].erase(key);
        if(freqToKeys[freq].empty()){
            freqToKeys.erase(freq);
            if(minFreq == freq){
                ++minFreq;
            }
        }
        keyToValueFreq[key].second++;
        freqToKeys[freq + 1].insert(key);
        return value;
    }

    void put(int key, int value){
        if(capacity == 0){
            return;
        }
        if(keyToValueFreq.find(key) != keyToValueFreq.end()){
            keyToValueFreq[key].first = value;
            get(key);
        }else{
            if(keyToValueFreq.size() >= capacity){
                int keyToRemove = *freqToKeys[minFreq].begin();
                freqToKeys[minFreq].erase(keyToRemove);
                if(freqToKeys[minFreq].empty()){
                    freqToKeys.erase(minFreq);
                }
                keyToValueFreq.erase(keyToRemove);
            }
            keyToValueFreq[key] = {value, 1};
            freqToKeys[1].insert(key);
            minFreq = 1;
        }
    }
};

int main(){
    LFUCache cache(3);
    cache.put(1, 10);
    cache.put(2, 15);
    cache.put(3, 20);
    cout << cache.get(1) << " "<< cache.get(2)<<endl;
    cache.put(4, 40);
    cout << cache.get(3) << endl;
    return 0;
}