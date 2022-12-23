#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findPiviotIndex(vector<int> &nums){
        int lastIndex=0;
        int piviotIndex;
        int low=0;
        int high=nums.size();
        while (true){
            int mid=(high+low)/2;
            int midVal=nums[mid];
            int midPlus1=nums[mid+1];
            int midMinus1=nums[mid-1];
            if(midPlus1>mid && midMinus1<mid && midPlus1>midMinus1){
                if()
            }else{
                piviotIndex=mid;
                break; 
            }
        }
    }
    int search(vector<int>& nums, int target) {
        
    }
};