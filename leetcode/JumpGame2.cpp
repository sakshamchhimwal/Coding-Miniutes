#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int checkIndex = nums.size()-1;
        while (1)
        {
            int maxValue=INT_MIN;
            int maxIndex=-1;
            for(int i=0;i<checkIndex-1;i++){
                if(nums.at(i)>maxValue){
                    maxValue=nums.at(i);
                    maxIndex=i;
                }
            }
            checkIndex=maxIndex;
            cout<<checkIndex<<'\t'<<maxIndex<<'\n';
        }
        
    }
};