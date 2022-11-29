#include <bits/stdc++.h>
using namespace std;

int distinct(int arr[], int s, int e)
{
    set<int> dis;
    for (int i = s; i < e; i++)
    {
        dis.insert(arr[i]);
    }
    int size = dis.size();
    return size;
}

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int limit;
    int c = INT_MIN;
    int ri, rj;
    n % 2 == 0 ? limit = n / 2 : limit = n / 2 + 1;
    for (int i = 0; i < limit; i++)
    {
        for (int j = n; j >= limit; j--)
        {
            int dis = distinct(arr, i, j);
            int x = j - i - dis;
            if (x >= c)
            {
                c = x;
                ri = i;
                rj = j;
            }
        }
    }
    cout << '\t' << ri << " " << rj << "\n";
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}