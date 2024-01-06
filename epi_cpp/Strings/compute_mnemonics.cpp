#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>

using namespace std;
const int kNumTelDigits = 10;
const array<string, kNumTelDigits> kMapping = {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void PhoneMnemonicHelper(const string& phone_number, int digit, 
                         string* partial_mnemonic, 
                         vector<string>* mnemonics){
    if(digit == phone_number.size()){
        mnemonics->emplace_back(*partial_mnemonic);
    }else{
        for(char c : kMapping[phone_number[digit] - '0']){
            (*partial_mnemonic)[digit] = c;
            PhoneMnemonicHelper(phone_number, digit + 1, partial_mnemonic, mnemonics);
        }
    }
}

vector<string> PhoneMnemonic(const string& phone_number){
    string partial_mnemonic(phone_number.size(), 0);
    vector<string> mnemonics;
    PhoneMnemonicHelper(phone_number, 0, &partial_mnemonic, &mnemonics);
    return mnemonics;
}

int main(){
    string phone_number = "2276696";
    auto result = PhoneMnemonic(phone_number);
    for(auto num : result){
        cout << num << endl;
    }
    return 0;
}