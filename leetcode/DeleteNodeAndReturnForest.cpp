#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
typedef struct TreeNode TreeNode;
class Solution{
private:
    vector<TreeNode*> result;
    bool search(vector<int> toDelete,int num){
        for(int i=0;i<toDelete.size();i++){
            if(toDelete[i]==num)
                return true;
        }
        return false;
    }
    void search(TreeNode root){
        if(search(root.val))
        //Left
        //Right
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
    }
};