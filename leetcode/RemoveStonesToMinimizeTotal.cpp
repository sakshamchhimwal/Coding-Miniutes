#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        for(int i=0;i<k;i++){
            sort(piles.begin(),piles.end());
            piles[piles.size()]=(piles[piles.size()]+1)/2;
        }
        int sum=0;
        for(int x:piles)
            sum+=x;
        return sum;
    }
};

int main(){
    Solution soln;
    vector<int> vec={};
    int k;
    double time=clock();
    soln.minStoneSum(vec,k);
    time-=clock();
    cout<<time/CLOCKS_PER_SEC;
}