#include<bits/stdc++.h>
#define MAX 1000000000
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int ans=0;
        int maxSize=0;
        for(int x:trainers){
            if(x>maxSize)
                maxSize=x;
        }
        vector<int> trainerLevel(maxSize,0);
        for(int x:trainers)
            trainerLevel[x-1]+=1;
        for(int x:players){
            while ((x-1)<maxSize && !trainerLevel[x-1]){
                x++;
            }
            if(trainerLevel[x-1]){
                ans++;
                trainerLevel[x-1]-=1;
            }
        }
        return ans; 
    }
};

int main(){
    Solution soln;
    vector<int> v1={4,7,9};
    vector<int> v2={8,2,5,8};
    cout<<soln.matchPlayersAndTrainers(v1,v2);
}