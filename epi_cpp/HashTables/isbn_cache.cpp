#include <iostream>
#include <unordered_map>
#include <list>


using namespace std;

template<size_t capacity>
class LRUCache{
private:
    typedef unordered_map<int, pair<list<int>::iterator, int>> Table;
    void MoveToFront(int isbn, const Table::iterator& it){
        lru_queue_.erase(it->second.first);
        lru_queue_.emplace_front(isbn);
        it->second.first = lru_queue_.begin();
    }
    Table isbn_price_table_;
    list<int> lru_queue_;
public:
    bool Lookup(int isbn, int* price){
        auto it = isbn_price_table_.find(isbn);
        if(it == isbn_price_table_.end()){
            return false;
        }
        *price = it->second.second;
        MoveToFront(isbn, it);
        return true;
    }

    void Insert(int isbn, int price){
        auto it = isbn_price_table_.find(isbn);
        if(it != isbn_price_table_.end()){
            MoveToFront(isbn, it);
        }else{
            if(isbn_price_table_.size() == capacity){
                isbn_price_table_.erase(lru_queue_.back());
                lru_queue_.pop_back();
            }
            lru_queue_.emplace_front(isbn);
            isbn_price_table_[isbn] = {lru_queue_.begin(), price};
        }
    }

    bool Erase(int isbn){
        auto it = isbn_price_table_.find(isbn);
        if(it == isbn_price_table_.end()){
            return false;
        }
        lru_queue_.erase(it->second.first);
        isbn_price_table_.erase(it);
        return true;
    }
};

int main(){
    auto cache = LRUCache<10>();
    for(int i=1; i<=5; ++i){
        cache.Insert(i, 10*i);
    }
    int price;
    if(cache.Erase(1)){
        cout << "Erase succeeded"<<endl;
    }else{
        cout << "Erase failed"<<endl;
    }
    for(int i=1; i <= 5; ++i){
        if(cache.Lookup(i, &price)){
            cout << "Price: "<<price<<endl;
        }else{
            cout << "Lookup failed for :"<< i << endl;
        }
    }
    return 0;
}