#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        int maxDiff = INT_MIN;
        int maxBags = 0;
        vector<int> keys;
        int n = capacity.size();
        for (int i = 0; i < n; i++)
        {
            int diff = capacity[i] - rocks[i];
            keys.push_back(diff);
            maxDiff = max(diff, maxDiff);
        }
        sort(keys.begin(),keys.end());
        int *diffCounter;
        diffCounter=(int *)malloc(sizeof(int)*(maxDiff+1));
        for(int x:keys)
            diffCounter[x]=0;
        for (int i = 0; i < n; i++)
        {
            int diff = capacity[i] - rocks[i];
            diffCounter[diff] += 1;
        }
        for(int j=0;j<keys.size();j++){
            int x=keys[j];
            if(additionalRocks>0 && diffCounter[x]!=0){
                if (x * diffCounter[x] < additionalRocks)
                {
                    maxBags += diffCounter[x];
                    additionalRocks -= diffCounter[x] * x;
                    diffCounter[x]=0;
                }
                else
                {
                    maxBags += additionalRocks / x;
                    additionalRocks -= (additionalRocks / x) * x;
                    diffCounter[x]-=(additionalRocks / x);
                }
            }
            while(j<keys.size() && keys[j]==x){
                j++;
            }
            j--;
        }
        return maxBags;
    }
};

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> diffList(capacity.size(),0);
        int maxBags=0;
        for(int i=0;i<capacity.size();i++){
            diffList[i]=capacity[i]-rocks[i];
        }
        sort(diffList.begin(),diffList.end());
        for(int i=0;i<diffList.size();i++){
            if(additionalRocks-diffList[i]>=0){
                maxBags++;
                additionalRocks-=diffList[i];
            }
            else
                break;
        }
        return maxBags;
    }
};

int main()
{
    
    vector<int> a, b;
    a = {10,1000000000};
    b = {10,0};
    Solution soln;
    double xxx = clock();
    cout<<soln.maximumBags(a, b, 1000000000);
    xxx = clock() - xxx;
    cout<<'\n'<<xxx/CLOCKS_PER_SEC;
}