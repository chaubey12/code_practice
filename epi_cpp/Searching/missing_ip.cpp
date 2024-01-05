#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int FindMissingElement(ifstream* ifs){
    const int kNumBucket = 1 << 16;
    vector<size_t> counter(kNumBucket, 0);
    unsigned int x;
    while(*ifs >> x){
        int upper_part_x = x >> 16;
        ++counter[upper_part_x];
    }
    const int kBucketCapacity = 1 << 16;
    int candidate_bucket;
    for(int i=0; i < kNumBucket; ++i){
        if(counter[i] < kBucketCapacity){
            candidate_bucket = i;
            break;
        }
    }
    ifs->clear();
    ifs->seekg(0, ios::beg);
    bitset<kBucketCapacity> bit_vec;
    while(*ifs >> x){
        int upper_part_x = x >> 16;
        if(candidate_bucket == upper_part_x){
            int lower_part_x = ((1 << 16) - 1)&x;
            bit_vec.set(lower_part_x);
        }
    }
    ifs->close();
    for(int i=0; i < kBucketCapacity; ++i){
        if(bit_vec[i] == 0){
            return (candidate_bucket << 16)|i;
        }
    }
}

int main(){
    return 0;
}