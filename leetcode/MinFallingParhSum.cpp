#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> rows){
        int max=INT_MAX;
        for(int x:rows){
            if(x<max){
                max=x;
            }
        }
        return max;
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int sum=0;
        for(vector<int> rows:matrix){
            int x=findMin(rows);
            sum+=x;
        }
        return sum;
    }
};

int main(){
    vector<vector<int>> matrix;
    Solution sol;
    matrix = {{2,1,3},{6,5,4},{7,8,9}};
    cout<<sol.minFallingPathSum(matrix);
}