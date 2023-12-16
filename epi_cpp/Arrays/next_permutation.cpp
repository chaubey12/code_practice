#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> NextPermutation(vector<int> perm){
    int k = perm.size() - 2;
    while(k >= 0 && perm[k] >= perm[k+1]){
        --k;
    }
    if(k == -1){
        return {};
    }
    for(int i = perm.size()-1; i > k; --i){
        if(perm[i] > perm[k]){
            swap(perm[k], perm[i]);
            break;
        }
    }
    reverse(perm.begin() + k + 1, perm.end());
    return perm;
}

int main(){
    vector<int> perm{2, 3, 5, 4};
    auto result = NextPermutation(perm);
    for(auto elem : result){
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}