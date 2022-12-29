#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int q=queries.size();
        int sum=0;
        vector<int> lastSum;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            lastSum.push_back(sum);
        }
        vector<int> ans(q,0);
        for(int i=0;i<q;i++){
            for(int j=0;j<n;j++){
                if(lastSum[j]<=queries[i]) ans[i]=j+1;
                else break;
            }
        }
        return ans;
    }
};