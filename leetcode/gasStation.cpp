#include<bits/stdc++.h>
using namespace std;

struct node{
    int fuel;
    int netFuel;
    struct node *next;
};
typedef struct node node;

class Solution1 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int maxDiffVal=INT_MIN;
        unordered_map<int,vector<int>> diffIndexMap;
        for(int i=0;i<gas.size();i++){
            if(gas[i]-cost[i]>maxDiffVal)
                maxDiffVal=gas[i]-cost[i];
            diffIndexMap[gas.at(i)-cost.at(i)].push_back(i);
        }
        if(gas.size()==1 && maxDiffVal<0) return -1;
        if(gas.size()==1 && maxDiffVal>=0) return 0;
        int currentCheckIndex=diffIndexMap[maxDiffVal].front();
        while (1){
            int netGas=0;
            int startIndex=currentCheckIndex;
            diffIndexMap[maxDiffVal].erase(diffIndexMap[maxDiffVal].begin());
            int i=0;
            for(;i<gas.size();i++){
                netGas+=gas[startIndex];
                if(netGas-cost[startIndex]<0) break;
                else{
                    netGas-=cost[startIndex];
                    (startIndex+1)<gas.size()?startIndex++:startIndex=((startIndex+1)%gas.size());
                }
            }
            if(i==gas.size()){
                return currentCheckIndex;
            }else{
                if(diffIndexMap[maxDiffVal].size()==0){
                    diffIndexMap.erase(maxDiffVal);
                    while(diffIndexMap.find(maxDiffVal)==diffIndexMap.end()){
                        maxDiffVal--;
                    }
                    if(maxDiffVal<0) return -1;
                    currentCheckIndex=diffIndexMap[maxDiffVal].front();
                }else{
                    currentCheckIndex=diffIndexMap[maxDiffVal].front();
                }
            }
        }
        return -1;
    }
};

class Solution{
    public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //makeNewOptimizedSolution
    }
};

int main(){
    cout<<"Running";
    Solution soln;
    vector<int> gas = {4};
    vector<int> cost = {5};
    cout<<soln.canCompleteCircuit(gas,cost);
}