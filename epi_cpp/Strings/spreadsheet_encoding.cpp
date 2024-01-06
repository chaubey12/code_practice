#include <iostream>
#include <string>
#include <vector>

using namespace std;

int SSDecodeColID(const string& col){
    int ret = 0;
    for(char c : col){
        ret = ret*26 + c - 'A' + 1;
    }
    return ret;
}

int main(){
    string col = "ZZ"; 
    cout << SSDecodeColID(col) << endl;
    return 0;
}