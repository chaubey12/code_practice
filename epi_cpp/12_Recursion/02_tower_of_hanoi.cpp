#include <iostream>
#include <vector>
#include <stack>
#include <array>

using namespace std;
const int kNumPegs = 3;

void ComputeTowerOfHanoiSteps(int num_rings, array<stack<int>, kNumPegs>& pegs, int from_peg, int to_peg, int use_peg){
    if(num_rings > 0){
        ComputeTowerOfHanoiSteps(num_rings - 1, pegs, from_peg, use_peg, to_peg);
        pegs[to_peg].emplace(pegs[from_peg].top());
        pegs[from_peg].pop();
        cout << "Ring "<<num_rings << " "<<from_peg << " "<<to_peg<<endl;
        ComputeTowerOfHanoiSteps(num_rings-1, pegs, use_peg, to_peg, from_peg);
    }
}

void ComputeTowerOfHanoi(int num_rings){
    array<stack<int>, kNumPegs> pegs;
    for(int i = num_rings; i > 0; --i){
        pegs[0].emplace(i);
    }
    ComputeTowerOfHanoiSteps(num_rings, pegs, 0, 1, 2);
}


int main(){
    ComputeTowerOfHanoi(4);
    return 0;
}