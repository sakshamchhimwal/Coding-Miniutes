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
    unordered_map<int,vector<int>> levelMap;
    void levelVal(TreeNode *root,int level){
        if(root)
            levelMap[level].push_back(root->val);
        if(root!=NULL && root->left)
            levelVal(root->left,level+1);
        if(root!=NULL && root->right)
            levelVal(root->right,level+1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode *root){
        vector<vector<int>> result={};
        levelVal(root,0);
        for(int i=0;levelMap[i].size()!=0;i++){
            result.push_back(levelMap[i]);
        }
        return result;
    }
};