#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int index1 = 0, index2 = 0;
        int minVal = INT_MAX;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (minVal >= nums.at(i))
            {
                minVal = nums.at(i);
                count++;
            }
        }
        if (count == nums.size())
        {
            sort(nums.begin(), nums.end());
            return;
        }
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums.at(i) < nums.at(i + 1))
            {
                index1 = i;
                index2 = i + 1;
            }
            else
            {
                if (nums.at(index1) < nums.at(i + 1))
                    index2 = i + 1;
            }
        }
        int temp = nums.at(index1);
        nums.at(index1) = nums.at(index2);
        nums.at(index2) = temp;
        for (int i = 0; i < (nums.size() - index1 - 1) / 2; i++)
        {
            int temp = nums.at(index1 + 1 + i);
            nums.at(index1 + 1 + i) = nums.at(nums.size() - 1 - i);
            nums.at(nums.size() - 1 - i) = temp;
        }
    }
};
