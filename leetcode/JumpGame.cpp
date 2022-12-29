#include <bits/stdc++.h>
using namespace std;

class Solution1
{
private:
    int check(vector<int> nums, int currIndex, int findIndex)
    {
        int ans = 0;
        if (currIndex >= findIndex)
        {
            ans += 1;
            return ans;
        }
        for (int i = currIndex; i < findIndex; i++)
        {
            if (nums[i] == 0)
                break;
            for (int j = nums[i]; j > 0; j--)
            {
                ans += check(nums, j + i, findIndex);
                if (ans)
                    return ans;
            }
        }
        return ans;
    }

public:
    bool canJump(vector<int> &nums)
    {
        if (check(nums, 0, nums.size() - 1))
            return true;
        return false;
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int finalIndex=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+i>finalIndex){
                finalIndex=nums[i]+i;
            }
            if(finalIndex<i+1){
                break;
            }
        }
        return finalIndex>=nums.size()-1;
    }
};

int main()
{
    cout << "Running\n";
    Solution soln;
    vector<int> v = {2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
    cout << soln.canJump(v);
}