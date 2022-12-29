#include<bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    struct node *left;
    struct node *right;
};

typedef struct node node;

class Solution{
public:
    int numTrees(int n){
        int ans=0;
        if(n==1 || n==0){
            return 1;
        }
        for(int i=1;i<n+1;i++){
            int size;
            //Left
            size=n-i;
            int ansL=numTrees(size);
            //Right
            size=i-1;
            int ansR=numTrees(size);
            //Total Combo
            ans+=ansL*ansR;
        }
        return ans;
    }
};

class Solution1{
public:
    int numTrees(int n){
        if(n<2)
            return 1;
        vector<int> solnHolder(n+1);
        solnHolder[0]=1;
        solnHolder[1]=1;
        solnHolder[2]=2;
        for(int i=3;i<n+1;i++){
            for(int j=0;j<i;j++){
                solnHolder[i]+=solnHolder[i-j-1]*solnHolder[j];
            }
        }
        return solnHolder[n];
    }
};

int main(){
    Solution solx;
    Solution1 soln;
    for(int i=1;i<20;i++){
        cout<<solx.numTrees(i)<<'\t'<<soln.numTrees(i)<<'\n';
    }
}