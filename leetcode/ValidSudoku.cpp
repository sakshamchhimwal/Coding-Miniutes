#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkCol(vector<vector<char>> &board)
    {   
        for (int i = 0;i < 9; i++)
        {
            int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (vector<char> x : board)
            {
                if (!arr[x.at(i)])
                {
                    arr[x.at(i)] = 1;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool checkRow(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (char x : board.at(i))
            {
                if (!arr[x])
                {
                    arr[x] = 1;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool checkSubSq(vector<vector<char>> &board)
    {
    }
    bool isValidSudoku(vector<vector<char>> &board)
    {
    }
};