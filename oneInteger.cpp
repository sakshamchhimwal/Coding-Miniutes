#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> nums) {
    sort(nums.begin(),nums.end());
    while(nums.size()!=1){
        if(nums[1]>nums[nums.size()-1]){
            int num1=nums.at(0);
            int num2=nums.at(nums.size()-1);
            nums.erase(nums.begin());
            nums.erase(nums.end()-1);
            nums.push_back(num1+num2);
        }else{
            int num1=nums.at(0);
            int num2=nums.at(1);
            nums.erase(nums.begin());
            nums.erase(nums.begin());
            nums.push_back(num1+num2);
        }
    }
    return nums[0];
}

int main(){
    cout<<solve({1,2,3,4,5});
}