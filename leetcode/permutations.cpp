#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fact(int n)
    {
        int val = 1;
        for (int i = 1; i <= n; i++)
        {
            val = val * i;
        }
        return val;
    }
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
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> holder;
        holder.insert(holder.begin(),nums);
        for (int i = 1; i < fact(nums.size()); i++)
        {
            this->nextPermutation(nums);
            holder.insert(holder.begin()+i,nums);
        }
        return holder;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> newVec={1,2,3};
    for(vector<int> x:sol.permute(newVec)){
        for(int y:x){
            cout<<y<<',';
        }
        cout<<'\n';
    }
    return 0;
}
