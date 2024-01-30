#include <iostream>
#include <vector>
#include <memory>
#include <limits>
#include <map>

using namespace std;

// int FindClosestElementsInSortedArrays(const vector<vector<int>>& sorted_arrays){
//     int min_distance_so_far = numeric_limits<int>::max();
//     struct IterTail{
//         vector<int>::const_iterator iter, tail;
//     };
//     multimap<int, IterTail> iter_and_tail;
//     for(const vector<int>& sorted_array : sorted_arrays){
//         iter_and_tail.emplace(sorted_array.front(), IterTail{sorted_array.cbegin(), sorted_array.cend()});
//     }
//     while(true){
//         int min_value = iter_and_tail.cbegin()->first;
//         int max_value = iter_and_tail.crbegin()->first;
//         cout << max_value << " " << min_value << endl;
//         min_distance_so_far = min(max_value - min_value, min_distance_so_far);
//         const auto next_min = next(iter_and_tail.cbegin()->second.iter),
//                    next_end = next(iter_and_tail.cbegin()->second.tail);
//         cout << *next_min  << endl;
//         if(next_min == next_end){
//             break;
//         }
//         iter_and_tail.emplace(*next_min, IterTail{next_min, next_end});   
//         iter_and_tail.erase(iter_and_tail.cbegin());
//     }
//     return min_distance_so_far;
// }

int FindClosestElementsInSortedArrays(const vector<vector<int>>& sorted_arrays){
    int min_distance_so_far = numeric_limits<int>::max();
    struct IterTail{
        vector<int>::const_iterator iter, tail;
    };
    multimap<int, IterTail> iter_and_tail;
    for(const vector<int>& sorted_array : sorted_arrays){
        iter_and_tail.emplace(sorted_array.front(), IterTail{sorted_array.cbegin(), sorted_array.cend()});
    }
    while(true){
        int min_value = iter_and_tail.cbegin()->first;
        int max_value = iter_and_tail.crbegin()->first;
        min_distance_so_far = min(max_value - min_value, min_distance_so_far);
        const auto next_min = next(iter_and_tail.cbegin()->second.iter),
                   next_end = iter_and_tail.cbegin()->second.tail;
        if(next_min == next_end){
            break;
        }
        iter_and_tail.emplace(*next_min, IterTail{next_min, next_end});   
        iter_and_tail.erase(iter_and_tail.cbegin());
    }
    return min_distance_so_far;
}

int main(){
    vector<int> A{5, 10, 14};
    vector<int> B{3, 6, 9, 12, 15};
    vector<int> C{8, 16, 24};
    vector<vector<int>> ip{A, B, C};
    cout << FindClosestElementsInSortedArrays(ip) << endl;
    return 0;
}