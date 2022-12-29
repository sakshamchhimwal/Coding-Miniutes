#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
private:
    bool isValSame(TreeNode *rootLeft,TreeNode *rootRight){
        if(rootLeft==NULL && rootRight==NULL) return true;
        if(rootLeft!=NULL && rootRight==NULL) return false;
        if(rootLeft==NULL && rootRight!=NULL) return false;
        if(rootLeft->val!=rootRight->val) return true; 
        bool ans=false,ansL=false,ansR=false;
        ansL=isValSame(rootLeft->left,rootRight->right);
        ansR=isValSame(rootLeft->right,rootRight->left);
        ans = ansL & ansR;
        return ans;
    }
public:
    bool isSymmetric(TreeNode *root){
        return isValSame(root->left,root->right);
    }
};