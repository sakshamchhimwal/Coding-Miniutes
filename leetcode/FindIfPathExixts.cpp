#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool allVisit(vector<int> checkList){
        for(int x:checkList){
            if(x!=INT_MIN) return false;
        }
        return true;
    }
    int closestNum(vector<int> checkList){
        for(int x:checkList){
            if(x!=INT_MIN) return x;
        }
        return INT_MIN;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> checkList;
        for(int i=0;i<n;i++){
            checkList.push_back(i);
        }
        unordered_map<int,vector<int>> listGraph;
        for(vector<int> x:edges){
            listGraph[x[0]].push_back(x[1]);
        }
        vector<int> dfsStack;
        dfsStack.push_back(source);
        while (!allVisit(checkList)){
            if(dfsStack.size()==0){
                dfsStack.push_back(closestNum(checkList));
            }
            if(listGraph[dfsStack.back()].size()>0){
                int top=dfsStack.back();
                int lastTop;
                while (checkList[top]!=INT_MIN && listGraph.find(dfsStack.back())!=listGraph.end()){
                    lastTop = top;
                    top=listGraph[dfsStack.back()].front();
                    dfsStack.push_back(top);
                    if(dfsStack.front()==source && dfsStack.back()==destination) return true;
                    listGraph[lastTop].erase(listGraph[lastTop].begin());
                    if(listGraph[lastTop].size()==0) checkList[lastTop]=INT_MIN;
                }
                dfsStack.erase(dfsStack.end());
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution soln;
    vector<vector<int>> graph = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    cout<<soln.validPath(6,graph,0,5);
    return 0;
}
