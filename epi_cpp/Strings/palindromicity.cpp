#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool IsPalndrome(const string& str){
    int i=0, j=str.size()-1;
    while(i < j){
        while(!isalnum(str[i]) && i < j){
            ++i;
        }
        while(!isalnum(str[j]) && i < j){
            --j;
        }
        if(tolower(str[i]) != (tolower(str[j]))){
            return false;
        }
        ++i, --j;
    }
    return true;
}


int main(){
    string line{"A man, a plan, a canal, Panama."};
    if(IsPalndrome(line)){
        cout << "IS PALINDROME"<<endl;
    }else{
        cout << "IS NOT PALINDROME"<<endl;
    }
    return 0;
}