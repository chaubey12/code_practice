#include <iostream>
#include <string>

using namespace std;

int StringHash(const string& str, int modulus){
    const int kMult = 997;
    int val=0;
    for(char c : str){
        val = (val*kMult + c)%modulus;
    }
    return val;
}

int main(){
    string str1 = "geeksforgeeks", str2 = "madhupchoubey", str3 = "anweshachoubey";
    int modulus = 11;
    cout << "Hash Values "<<endl;
    cout << str1 << " " << StringHash(str1, modulus)<<endl;
    cout << str2 << " " << StringHash(str2, modulus)<<endl;
    cout << str3 << " " << StringHash(str3, modulus)<<endl;
    return 0;
}