#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int index = -1;
        for (int i = 0; i < haystack.size(); i++)
        {
            if (haystack[i] == needle[0])
            {
                index = i;
                int count = 0;
                for (int j = i; j < haystack.size(); j++)
                {
                    if (haystack[j] != needle[j - i])
                    {
                        break;
                    }
                    count++;
                }
                if (count == needle.size())
                {
                    return index;
                }else{
                    index=-1;
                }
            }
        }
        return index;
    }
};

int main(){
    Solution newSol;
    cout << newSol.strStr("leetcode", "leeto");
}