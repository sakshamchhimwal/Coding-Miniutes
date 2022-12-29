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
typedef struct TreeNode node;

node * makeNode(int i){
    node *newNode =(node *)malloc(sizeof(node));
    newNode->val=i;
    newNode->left=newNode->right=NULL;
    return newNode;
}

class Solution{
public:
    vector<int> inList;
    void inorder(TreeNode *root){
        if(root==NULL)
            return;
        inorder(root->left);
        inList.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode *root){
        inorder(root);
        long int maxVal=INT64_MIN;
        for(int i=0;i<inList.size();i++){
            if(inList[i]>maxVal){
                maxVal=inList[i];
            }else{
                return false;
            }
        }
        return true;
    }
};

int main(){
    node *root;
    root=makeNode(5);
    root->left=makeNode(1);
    root->right=makeNode(4);
    root->right->left=makeNode(3);
    root->right->left=makeNode(6);
    Solution soln;
    cout<<soln.isValidBST(root);
}
