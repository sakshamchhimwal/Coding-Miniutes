#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int zeros = 0, ones = 0, twos = 0;
        for (int x : nums)
        {
            if (x == 0)
                zeros++;
            if (x == 1)
                ones++;
            if (x == 2)
                twos++;
        }
        int i = 0;
        while (i < nums.size())
        {
            if (zeros > 0)
            {
                nums[i]=0;
                zeros--;
            }
            else if (zeros == 0 && ones > 0)
            {
                nums[i]= 1;
                ones--;
            }
            else if (zeros == 0 && ones == 0 && twos > 0)
            {
                nums[i] = 2;
                twos--;
            }
            else{
                break;
            }
            i++;
        }
    }
};

int main()
{
    Solution newSoln;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    newSoln.sortColors(nums);
    for(auto x:nums){
        cout<<x<<',';
    }
}