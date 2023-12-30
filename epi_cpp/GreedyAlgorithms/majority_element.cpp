#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string MajoritySearch(istringstream* input_stream){
    string candidate, iter;
    int candidate_count=0;
    while(*input_stream >> iter){
        if(candidate_count == 0){
            candidate = iter;
            candidate_count = 1;
        }else if(candidate == iter ){
            ++candidate_count;
        }else{
            --candidate_count;
        }
    }
    return candidate;
}

int main(){
    string input_strings = "b a c a a b a a c a b b b b b b b b";
    istringstream ss(input_strings);
    cout << "Majority element is : "<<MajoritySearch(&ss)<<endl;

    return 0;
}