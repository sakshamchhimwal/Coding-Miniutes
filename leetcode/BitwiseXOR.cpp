#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int,int> freqmap;
        long long int sizeList1=nums1.size();
        sizeList1%2==0?sizeList1=0:sizeList1=1;
        long long int sizeList2=nums2.size();
        sizeList2%2==0?sizeList2=0:sizeList2=1;
        for(int x:nums1){
            if(freqmap.find(x)==freqmap.end()){
                freqmap[x]=sizeList2;
            }else{
                freqmap[x]+=sizeList2;
            }
        }
        for(int x:nums2){
            if(freqmap.find(x)==freqmap.end()){
                freqmap[x]=sizeList1;
            }else{
                freqmap[x]+=sizeList1;
            }
        }
        int initXOR=0;
        for(auto x:freqmap){
            if(x.second%2==0){
                initXOR=initXOR^0;
            }else{
                initXOR=initXOR^x.first;
            }
        }
        return initXOR;
    }
};

int main(int argc, char const *argv[])
{
    Solution son;
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    cout << son.xorAllNums(nums1, nums2);
    // long long int x;
    // x=4^3;
    // cout<<x;
    return 0;
}
