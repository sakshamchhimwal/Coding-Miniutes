#include <bits/stdc++.h>
using namespace std;

#define print cout

int findKthLargest(vector<int> nums, int k)
{
    sort(nums.begin(),nums.end());
    for(int x: nums){
        print<<x;
    }
}

int main(int argc, char const *argv[])
{
    vector <int> nums= { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
    print<<findKthLargest(nums,4);
    return 0;
}
