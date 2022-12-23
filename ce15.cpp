#include<bits/stdc++.h>
using namespace std;

int countTriplets(vector<int> nums) {
    int count=0;
    for (int i = 0; i < nums.size(); i++) {
        for(int j=0;j<nums.size();j++){
            for(int k=0;k<nums.size();k++){
                if(!(nums[i] & nums[j] & nums[k])) count++;
            }
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    cout<<countTriplets({2,1,3});
    return 0;
}
