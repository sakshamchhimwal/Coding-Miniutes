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
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->val=i;
    newNode->left=newNode->right=NULL;
    return newNode;
}

class Solution{
public:
    bool isSameTree(TreeNode *p, TreeNode *q){
        bool ans=true,ansL=true,ansR=true;
        if(p==NULL && q==NULL){
            return true;
        }
        if(p!=NULL && q==NULL){
            return false;
        }
        if(p==NULL && q!=NULL){
            return false;
        }
        if(p->val!=q->val){
            return false;
        }
        //Left
        if((p->left!=NULL && q->left==NULL) || (p->left==NULL && q->left!=NULL)){
            ansL=false;
        }else{
            ansL=isSameTree(p->left,q->left);
        }
        //Right
        if((p->right!=NULL && p->right==NULL) || (p->right==NULL && q->right!=NULL)){
            ansR=false;
        }else{
            ansR=isSameTree(p->right,q->right);
        }
        ans=ansR & ansL;
        if(!ans)
            return false;
        else
            return true;
    }
};
int main(int argc, char const *argv[])
{
    node *p = makeNode(0);
    node *q = makeNode(0);
    p->left=makeNode(1);
    q->left=makeNode(1);
    Solution soln;
    cout<<soln.isSameTree(p,q);
    return 0;
}
