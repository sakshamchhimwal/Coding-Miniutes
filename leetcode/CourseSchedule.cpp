#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool FindCycle(int maxNode,vector<vector<int>>& prerequisites){
        unordered_map<int,vector<int>> graphMap;
        int *visitedArr=(int *)malloc(sizeof(int)*maxNode);
        for(int i=0;i<maxNode;i++){
            visitedArr[i]=0;
            graphMap[i]={};
        }
        for(int i=0;i<prerequisites.size();i++)
            graphMap[prerequisites[i][0]].push_back(prerequisites[i][1]);

        //DFS
        









        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
    }
};