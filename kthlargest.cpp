#include<bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> nums, int k){
    sort(nums.begin(),nums.end());
    int nthLargest = 0;
    for(int i=0;i<nums.size();i++){
        while(nums[i+1]==nums[i]){
            i++;
        }
        nthLargest+=1;
        if(nthLargest==k){
            return nums[i];
        }
    }
}

int main(){
    vector<int> arr={3,2,3,1,2,4,5,5,6};
    cout<<findKthLargest(arr,4);
}