#include <iostream>
#include <vector>
#include <string>

using namespace std;

int ReplaceAndRemove(int size, char s[]){
    int write_idx = 0, a_count = 0;
    for(int i=0; i < size; ++i){
        if(s[i] != 'b'){
            s[write_idx++] = s[i];
        }
        if(s[i] == 'a'){
            ++a_count;
        }
    }
    int curr_idx = write_idx - 1;
    write_idx = write_idx + a_count - 1;
    int final_size = write_idx + 1;
    while (curr_idx >= 0){
        if(s[curr_idx] == 'a'){
            s[write_idx--] = 'd';
            s[write_idx--] = 'd';
        }else{
            s[write_idx--] = s[curr_idx];
        }
        --curr_idx;
    }
    return final_size;
}

int main(){
    char s[] = {'a', 'c', 'd', 'b', 'b', 'c', 'a'};
    int size = 7;
    cout << ReplaceAndRemove(size, s) << endl;
    return 0;
}