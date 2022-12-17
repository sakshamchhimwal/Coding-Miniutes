#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int f = 0, l = height.size() - 1;
        int maxA = INT_MIN;
        while (l > 0 && f < height.size() - 1)
        {
            int h = min({height.at(f), height.at(l)});
            int w = l - f;
            int a = h * w;
            a > maxA ? maxA = a : maxA = maxA;
            int newHeight = min({height.at(f + 1), height.at(l)}) * (w - 1);
            if (min({height.at(f + 1), height.at(l)}) * (w - 1) > a)
                f = f + 1;
            else if (min({height.at(f), height.at(l-1)}) * (w - 1) > a)
                l = l - 1;
            else{
                l=l-1;
                f=f+1;
            }
        }
        return maxA;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> vec = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    cout << sol.maxArea(vec);
    return 0;
}
