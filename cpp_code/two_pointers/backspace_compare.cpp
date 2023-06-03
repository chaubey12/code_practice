#include <iostream>
#include <string>

using namespace std;

class BackspaceCompare{
public:
    static bool compare(string& s1, string& s2){
        int i1 = s1.length() - 1, i2 = s2.length() - 1;
        while(i1 >= 0 || i2 >= 0){
            int idx1 = getNextValidIndex(s1, i1);
            int idx2 = getNextValidIndex(s2, i2);
            if(idx1 < 0 && idx2 < 0){
                return true;
            }
            if(idx1 < 0 || idx2 < 0){
                return false;
            }
            if(s1[idx1] != s2[idx2]){
                return false;
            }
            i1 = idx1 - 1;
            i2 = idx2 - 1;
        }
        return true;
    }
private:
    static int getNextValidIndex(string& s, int i){
        int count = 0;
        while(i >= 0){
            if(s[i] == '#'){
                count++;
            }else if(count > 0){
                count--;
            }else{
                break;
            }
            i--;
        }
        return i;
    }
}; 


int main(){
    string s1 = "oo#uu#tt#";
    string s2 = "out";
    if(BackspaceCompare::compare(s1, s2)){
        cout << "Identical Strings";
    }else{
        cout << "Different Strings";
    }
    cout << endl;
    return 0;
}