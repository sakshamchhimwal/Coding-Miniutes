#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        unordered_map<int,int> targetMap;
        vector<vector<int>> test;
        for (int i = 0; i < nums.size(); i++)
        {
            unordered_map<int, int> checkMap;
            int target = (-1) * nums.at(i);
            for (int j = 0; j < nums.size(); j++)
            {
                int node = nums.at(j);
                int comp = target - node;
                if (checkMap.count(comp))
                {
                    if (targetMap.find((-1)*target)==targetMap.end())
                    {
                        test.push_back({(-1) * target, node, comp});
                        targetMap[(-1)*target]=1;
                    }
                }
                checkMap[node] = i;
            }
        }
        return test;
    }
};

int main()
{
    cout << "Runnung\n";
    Solution soln;
    vector<int> newVec = {-1,0,1,2,-1,-4};
    for (vector<int> x : soln.threeSum(newVec))
    {
        for (int y : x)
        {
            cout << y << ',';
        }
        cout << '\n';
    }
}