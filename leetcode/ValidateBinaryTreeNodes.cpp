
//PENDINGGGGG

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> inorderList={};
    int count=0;
    void inorder(int root,vector<int>& L,vector<int>& R){
        if(count<2*(L.size()+1)) count++;
        else return;
        if(root==-1){
            return;
        }
        inorder(L[root],L,R);
        inorderList.push_back(root);
        inorder(R[root],L,R);
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        inorder(0,leftChild,rightChild);
        if(inorderList.size()<n) return false;
        sort(inorderList.begin(),inorderList.end());
        for(int i=0;i<inorderList.size()-1;i++){
            if(inorderList[i]==inorderList[i+1])
                return false;
        }
        return true;
    }
};

int main(){
    int n=6;
    vector<int> lchild={1,-1,-1,4,-1,-1};
    vector<int> rchild={2,-1,-1,5,-1,-1};
    Solution soln;
    cout<<soln.validateBinaryTreeNodes(n,lchild,rchild);
}