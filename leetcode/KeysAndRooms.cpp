#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAllVisited(vector<int> visitedList){
        for(int x:visitedList)
            if(x!=1)
                return false;
        return true;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms){
        int largestRoom = INT_MIN;
        unordered_map<int,vector<int>> roomMap;
        int k=0;
        for(vector<int> x:rooms){
            if(k>largestRoom) largestRoom=k;
            for(int i=0;i<x.size();i++){
                if(x[i]>largestRoom) largestRoom=x[i];
                roomMap[k].push_back(x[i]);
            }
            k++;
        }
        vector<int> visitedList;
        for(int i=0;i<largestRoom+1;i++){
            visitedList.push_back(0);
        }
        stack<int> dfsStack;
        dfsStack.push(0);
        int top,lastTop;
        while (!dfsStack.empty()){
            top=dfsStack.top();
            lastTop=top;
            visitedList[top]=1;
            while (roomMap[lastTop].size()!=0){
                if(visitedList[roomMap[lastTop].front()]==0)
                    dfsStack.push(roomMap[lastTop].front());
                roomMap[lastTop].erase(roomMap[lastTop].begin());
                lastTop=dfsStack.top();
                visitedList[lastTop]=1;
            }   
            dfsStack.pop();
        }
        if(isAllVisited(visitedList))
            return true;
        return false;
    }
};

int main(int argc, char const *argv[])
{
    cout<<"Running\n";
    Solution soln;
    vector<vector<int>> graph={{1,3},{3,0,1},{2},{0}};
    cout<<soln.canVisitAllRooms(graph);
    return 0;
}
