#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeStars(string s) {
        int j = 0;
        for(auto c: s){
            if (c == '*') j--;
            else s[j++] = c;
        }
        return s.substr(0, j);
    }
};
int main(int argc, char const *argv[])
{
    cout<<"Running\n";
    Solution soln;
    string s="leet**cod*e";
    cout<<soln.removeStars(s);
    return 0;
}
