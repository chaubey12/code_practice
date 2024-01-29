#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <sstream>
#include <array>

using namespace std;
struct Star{
    bool operator<(const Star& that) const{
        return Distance() < that.Distance();
    }
    double x, y, z;
    double Distance() const { return sqrt(x*x + y*y + z*z);}
};

vector<Star> FindClosestKStars(int k, istringstream* stars){
    priority_queue<Star, vector<Star>> max_heap;
    string line;
    while(getline(*stars, line)){
        stringstream line_stream(line);
        array<double, 3> data;
        for(int i=0; i < 3; ++i){
            string buf;
            getline(line_stream, buf, ',');
            data[i] = stod(buf);
        }
        max_heap.emplace(Star{data[0], data[1], data[2]});
        if(max_heap.size() > k){
            max_heap.pop();
        }
    }
    vector<Star> closest_stars;
    while(!max_heap.empty()){
        closest_stars.emplace_back(max_heap.top());
        max_heap.pop();
    }
    reverse(closest_stars.begin(), closest_stars.end());
    return closest_stars;
}

int main(){
    string stream = "1,3,1\n2,5,7\n3,1,4\n4,1,2";
    istringstream ss(stream);
    int k = 2;
    auto stars = FindClosestKStars(k, &ss);
    for(auto star : stars){
        cout << star.x <<" "<<star.y << " "<<star.z << " Distance:"<<star.Distance()<<endl;
    }
    cout << endl;
    return 0;
}