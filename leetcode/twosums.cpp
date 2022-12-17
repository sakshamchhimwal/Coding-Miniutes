#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool findSubarrays(vector<int> &nums)
    {
        unordered_map<int /*Sum*/, int /*Count*/> sumCount;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int calcSum = nums.at(i) + nums.at(i + 1);
            if (!sumCount[calcSum])
            {
                sumCount[calcSum] = 1;
            }
            else
            {
                sumCount[calcSum]++;
            }
        }
        for (auto c : sumCount)
        {
            if (c.second > 1)
            {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> arr = {1, -1, 1, -1, 1, -1, 1};
    cout << sol.findSubarrays(arr);
}
