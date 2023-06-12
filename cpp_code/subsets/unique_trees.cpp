#include <iostream>
#include <vector>

using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) { data = x;}
};

void printInorder(TreeNode* root){
    if(root){
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }
}

void printPreorder(TreeNode* root){
    if(root){
        cout << root->data << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

class UniqueTrees{
public:
    static vector<TreeNode*> findUniqueTrees(int n){
        if(n <= 0){
            return vector<TreeNode*>();
        }
        return findUniqueTreesRecursive(1, n);
    }
    static vector<TreeNode*> findUniqueTreesRecursive(int start, int end){
        vector<TreeNode*> result;
        if(start > end){
            result.push_back(nullptr);
            return result;
        }
        for(int i = start; i <= end; i++){
            vector<TreeNode*> leftResult = findUniqueTreesRecursive(start, i-1);
            vector<TreeNode*> rightResult = findUniqueTreesRecursive(i+1, end);
            for(auto leftTree : leftResult){
                for(auto rightTree : rightResult){
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};

int main(){
    vector<TreeNode*> trees = UniqueTrees::findUniqueTrees(6);
    for(auto tree : trees){
        cout << "Inorder :";
        printInorder(tree); 
        cout << endl; 
        cout << "Preorder :";
        printPreorder(tree); 
        cout << endl; 
    }
    return 0;
}