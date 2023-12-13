#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

struct Subarray{
    int start, end;
};

Subarray FindSmallestSubarrayCoveringSet(const vector<string>& paragraph, const vector<string>& keywords){
    unordered_map<string, int> keywords_to_cover;
    for(const string& keyword : keywords){
        ++keywords_to_cover[keyword];
    }
    Subarray result = Subarray{-1, -1};
    int remaining_to_cover = keywords_to_cover.size();
    for(int left=0, right=0; right < paragraph.size(); ++right){
        if(keywords_to_cover.count(paragraph[right]) && --keywords_to_cover[paragraph[right]] >= 0){
            --remaining_to_cover;
        }
        while(remaining_to_cover == 0){
            if((result.start == -1 && result.end == -1) || (right - left) < (result.end - result.start)){
                result = {left, right};
            }
            if(keywords_to_cover.count(paragraph[left]) && ++keywords_to_cover[paragraph[left]] > 0){
                ++remaining_to_cover;
            }
            ++left;
        }
    }
    return result;
}

int main(){
    vector<string> paragraph = {"this", "is", "the", "most", "cruel", "place"};
    vector<string> keywords = {"most", "cruel"};
    auto result = FindSmallestSubarrayCoveringSet(paragraph, keywords);
    cout << "Start {" << result.start <<", "<<result.end << "}"<<endl;
    return 0;
}