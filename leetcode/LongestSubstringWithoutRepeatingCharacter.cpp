#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, vector<int>> locs;
        int maxSize = 0;
        int testMaxSize = 0;
        int lastBreak=-1;
        for (int i = 0; i < s.size(); i++)
        {

            if (locs.find(s[i]) == locs.end())
            {
                locs[s[i]];
                locs[s[i]].insert(locs[s[i]].end(), i);
                testMaxSize++;
                if (testMaxSize > maxSize)
                {
                    maxSize = testMaxSize;
                }
            }
            else
            {
                locs[s[i]].insert(locs[s[i]].end(), i);
                if(locs[s[i]].at(0)>lastBreak){
                    lastBreak=locs[s[i]].at(0);
                    testMaxSize = testMaxSize - locs[s[i]].at(0);
                }else{
                    testMaxSize++;
                }
                locs[s[i]].erase(locs[s[i]].begin());
                if (testMaxSize > maxSize)
                    maxSize = testMaxSize;
            }
        }
        return maxSize;
    }
};
int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.lengthOfLongestSubstring("tmmzuxt");
    return 0;
}
