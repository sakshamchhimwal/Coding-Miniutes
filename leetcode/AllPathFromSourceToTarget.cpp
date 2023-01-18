#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    vector<vector<int>> result;
    void dfs(vector<vector<int>>& graph,int graphIndex,vector<int> &res,int size){
        if(graphIndex==size-1){
            result.push_back(res);
            return;
        }
        for(int x:graph[graphIndex]){
            res.push_back(x);
            dfs(graph,x,res,size);
            res.pop_back();
        }
    } 
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
        vector<int> res={0};
        dfs(graph,0,res,graph.size());
        return result;
    }
};

int main(){
    vector<vector<int>> graph={{4,3,1},{3,2,4},{3},{4},{}};
    Solution soln;
    for(vector<int> x:soln.allPathsSourceTarget(graph)){
        for(int y:x){
            cout<<y<<',';
        }
        cout<<'\n';
    }
}