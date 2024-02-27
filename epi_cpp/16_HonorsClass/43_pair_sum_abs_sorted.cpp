#include <iostream>
#include <vector>

using namespace std;

struct IndexPair{
    int index_1, index_2;
};

template <typename Compare>
IndexPair FindPairUsingCompare(const vector<int>& A, int k, Compare comp){
    IndexPair result = IndexPair{0, static_cast<int>(A.size() - 1)};
    while(result.index_1 < result.index_2 && comp(A[result.index_1], 0)){
        ++result.index_1;
    }
    while(result.index_1 < result.index_2 && comp(A[result.index_2], 0)){
        --result.index_2;
    }
    while(result.index_1 < result.index_2){
        if(A[result.index_1] + A[result.index_2] == k){
            return result;
        }else if(comp(A[result.index_1] + A[result.index_2], k)){
            do{
                ++result.index_1;
            }while(result.index_1 < result.index_2 && comp(A[result.index_1], 0));
        }else{
            do{
                --result.index_2;
            }while(result.index_1 < result.index_2 && comp(A[result.index_2], 0));
        }
    }
    return {-1, -1};
}

IndexPair FindPositiveNegativePair(const vector<int>& A, int k){
    IndexPair result = IndexPair{static_cast<int>(A.size() - 1), static_cast<int>(A.size() - 1)};
    while(result.index_1 >= 0 && A[result.index_1] < 0){
        --result.index_1;
    }
    while(result.index_2 >= 0 && A[result.index_2] >= 0){
        --result.index_2;
    }
    while(result.index_1 >= 0 && result.index_2 >= 0){
        if(A[result.index_1] + A[result.index_2] == k){
            return result;
        }else if(A[result.index_1] + A[result.index_2] > k){
            do{
                --result.index_1;
            }while(result.index_1 >= 0 && A[result.index_1] < 0);
        }else{
            do{
                --result.index_2;
            }while(result.index_2 >= 0 && A[result.index_2] >= 0);
        }
    }
    return {-1, -1};
}

IndexPair FindPairSumK(const vector<int>& A, int k){
    IndexPair result = FindPositiveNegativePair(A, k);
    if(result.index_1 == -1 && result.index_2 == -1){
        return k >= 0 ? FindPairUsingCompare(A, k, less<int>())
                      : FindPairUsingCompare(A, k, greater<int>());
    }
    return result;
}

int main(){
    vector<int> A{-49, 75, 103, -147, 164, -197, -238, 314, 348, -422};
    int k=167;
    auto result = FindPairSumK(A, k);
    cout << "("<<result.index_1 << ","<<result.index_2<<")"<<endl;
    return 0;
}