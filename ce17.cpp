#include<bits/stdc++.h>
using namespace std;

int checkHammingDis(int a,int b){
    int counter=0;
    int bitA,bitB;
    while (a>0 && b>0)
    {
        counter++;
        bitA=a & 1;
        a=a>>1;
        bitB=b & 1;
        b=b>>1;
        if(bitA!=bitB){
            return counter;
        }
    }
    return counter;
}

int totalHammingDistance(vector<int> nums) {
    int sum=0;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            sum+=checkHammingDis(nums[i],nums[j]);
        }
    }
    return sum;
}
int main(){
    cout<<totalHammingDistance({4,14,2});
}