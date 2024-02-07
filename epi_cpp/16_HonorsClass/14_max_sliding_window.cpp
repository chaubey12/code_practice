#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
class QueueWithMax{
private:
    queue<T> entries_;
    queue<T> candidates_for_max_;
public:
    void Enqueue(const T& x){
        entries_.emplace(x);
        while(!candidates_for_max_.empty()){
            if(candidates_for_max_.back() >= x){
                break;
            }
            candidates_for_max_.pop();
        }
        candidates_for_max_.emplace(x);
    }

    T Dequeue(){
        if(!entries_.empty()){
            T result = entries_.front();
            if(result == candidates_for_max_.front()){
                candidates_for_max_.pop();
            }
            entries_.pop();
            return result;
        }
        throw length_error("empty queue");
    }
    const T& Max() const{
        if(!candidates_for_max_.empty()){
            return candidates_for_max_.front();
        }
        throw length_error("empty queue");
    }
};

struct TrafficElement{
    bool operator>(const TrafficElement& that) const{
        return volume > that.volume ||
            (volume == that.volume && time > that.time);
    }

    bool operator==(const TrafficElement& that) const{
        return time == that.time && volume == that.volume;
    }

    bool operator >=(const TrafficElement& that) const{
        return *this > that || *this == that;
    }
    int time;
    double volume;
};

vector<TrafficElement> CalculateTrafficVolume(const vector<TrafficElement>& A, int w){
    QueueWithMax<TrafficElement> sliding_window;
    vector<TrafficElement> maximum_volume;
    for(const auto traffic_info : A){
        sliding_window.Enqueue(traffic_info);
        while(traffic_info.time - sliding_window.Max().time > w){
            sliding_window.Dequeue();
        }
        maximum_volume.emplace_back(TrafficElement{traffic_info.time, sliding_window.Max().volume});
    }
    return maximum_volume;
}

int main(){
    vector<TrafficElement> A{{0, 1.3}, {2, 2.5}, {3, 3.7}, {5, 1.4}, {6, 2.6}, {8, 2.2}, {9, 1.7}, {14, 1.1}};
    int w = 5;
    auto result = CalculateTrafficVolume(A, w);
    for(auto elem : result){
        cout << elem.time<<" ,"<<elem.volume<<endl;
    }
    return 0;
}