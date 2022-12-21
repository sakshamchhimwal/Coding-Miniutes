#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures){
        unordered_map<int,vector<int>> tempmap;
        int minTemp=INT_MAX,maxTemp=INT_MIN;
        for(int i=0;i<temperatures.size();i++){
            if(tempmap.find(temperatures.at(i))==tempmap.end()){
                tempmap[temperatures.at(i)].push_back(i);
            }else{
                if(tempmap.find(temperatures.at(i))!=tempmap.end()){
                    
                }
            }
        }
    }
};