#include <iostream>
#include <vector>

using namespace std;

class TreeNode{

};

class CountUniqueTrees{
public:
    static int countTrees(int n){
        if(n <= 1){return 1;}
        int count = 0;
        for(int i = 1; i <= n; i++){
            int countOfLeftSubtrees = countTrees(i - 1);
            int countOfRightSubtrees = countTrees(n - i);
            count += (countOfLeftSubtrees * countOfRightSubtrees);
        }
        return count;
    }
};

int main(){
    int n = 4;
    cout << "UniqueTrees count = " << CountUniqueTrees::countTrees(n) << endl;
    return 0;
}