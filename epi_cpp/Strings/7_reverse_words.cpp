#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void ReverseWords(string * s){
    reverse(s->begin(), s->end());
    size_t start=0, end;
    while ((end = s->find(" ", start)) != string::npos){
        reverse(s->begin() + start, s->begin() + end);
        start = end + 1;
    }
    reverse(s->begin() + start, s->end());
}

int main(){
    string str = "Alice likes Bob";
    ReverseWords(&str);
    cout << str<<endl;
    return 0;
}