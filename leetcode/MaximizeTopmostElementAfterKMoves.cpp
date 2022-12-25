#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int maxVal=INT_MIN;
        int indexMaxVal=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxVal){
                maxVal=nums[i];
                i<=k?indexMaxVal=i:indexMaxVal=indexMaxVal;
            }
        }
        if(nums.size()==1 && k%2!=0) return -1;
        // if(indexMaxVal%2!=0 && k%2==0 && indexMaxVal>=k-1){
        //     int nLeft=INT_MIN,nRight=INT_MIN;
        //     indexMaxVal>=1?nLeft=nums[indexMaxVal-1]:nLeft=nLeft;
        //     indexMaxVal<nums.size()-2?nRight=nums[indexMaxVal+1]:nRight=nRight;
        //     if(nLeft>nRight){
        //         return nLeft;
        //     }else{
        //         return nRight;
        //     }
        // }
        // return nums[indexMaxVal];
        if(k==indexMaxVal) return nums[indexMaxVal];
        if(k>nums.size()){
            if((k%2==0 && indexMaxVal%2==0) || (k%2!=0 && indexMaxVal%2!=0)) return nums[indexMaxVal];
            else{
                int nextMax=INT_MIN;
                for(int i=0;i<nums.size();i++){
                    if(nums[i]>nextMax && nums[i]<maxVal){
                        nextMax=nums[i];
                    }
                }
                return nextMax;
            }
        }else{
            if((k-indexMaxVal)%2==0) return nums[indexMaxVal];
            else{
                int nextMax=INT_MIN;
                for(int i=0;i<k;i++){
                    if(nums[i]>nextMax && nums[i]<maxVal){
                        nextMax=nums[i];
                    }
                }
                return nextMax;
            }
        }
        return -1;
    }
};

int main(){
    Solution soln;
    vector<int> test={48,68,97,6,81,42,61,16,11,27,63,37,36};
    cout<<soln.maximumTop(test,70);
}