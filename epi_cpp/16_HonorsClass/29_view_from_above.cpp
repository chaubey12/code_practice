#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
struct LineSegment{
    int left, right;
    int color;
    int height;
};

class Endpoint{
public:
    bool operator<(const Endpoint& that) const{
        return  Value() < that.Value();
    }
    int Value() const{
        return isLeft_ ? line_->left : line_->right;
    }
    bool isLeft_;
    const LineSegment* line_;
};

vector<LineSegment> CalculateViewFromAbove(const vector<LineSegment>& A){
    vector<Endpoint> sorted_endpoints;
    for(const LineSegment& a : A){
        sorted_endpoints.emplace_back(Endpoint{true, &a});
        sorted_endpoints.emplace_back(Endpoint{false, &a});
    }
    sort(sorted_endpoints.begin(), sorted_endpoints.end());
    vector<LineSegment> result;
    int prev_xaxis = sorted_endpoints.front().Value();
    unique_ptr<LineSegment> prev = nullptr;
    map<int, const LineSegment*> active_line_segments;
    for(const Endpoint& endpoint : sorted_endpoints){
        if(!active_line_segments.empty() && prev_xaxis != endpoint.Value()){
            if(prev == nullptr){
                prev = make_unique<LineSegment>(
                    LineSegment{
                        prev_xaxis, endpoint.Value(),
                        active_line_segments.crbegin()->second->color,
                        active_line_segments.crbegin()->second->height
                    }
                );
            }else{
                if(prev->height == active_line_segments.crbegin()->second->height &&
                   prev->color == active_line_segments.crbegin()->second->color &&
                   prev_xaxis == prev->right){
                    prev->right = endpoint.Value();
                }else{
                    result.emplace_back(*prev);
                    *prev = {prev_xaxis, endpoint.Value(),
                             active_line_segments.crbegin()->second->color,
                             active_line_segments.crbegin()->second->height};
                }
            }
        }
        prev_xaxis = endpoint.Value();
        if(endpoint.isLeft_ == true){
            active_line_segments.emplace(endpoint.line_->height, endpoint.line_);
        }else{
            active_line_segments.erase(endpoint.line_->height);
        }
    }
    if(prev){
        result.emplace_back(*prev);
    }
    return result;
}

int main(){
    return 0;
}