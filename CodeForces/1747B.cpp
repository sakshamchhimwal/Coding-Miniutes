/**
 * @file 1747B.cpp
 * @author your name (you@domain.com)
 * @brief Algorithm is correct till 10k lines of op but CF is not accepting
 * @version 0.1
 * @date 2022-11-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <bits/stdc++.h>
using namespace std;
FILE *fp_w;
void solve(int n)
{
    // int n;
    // cin >> n;
    string s = "";
    for (int i = 0; i < n; i++)
    {
        s.append("BAN");
    }
    // n % 2 == 0 ? cout << n / 2 : cout << n / 2 + 1;
    // cout << '\n';
    if (n % 2 != 0)
    {
        for (int i = 0,j=0; i < 3*(n / 2); i+=3,j++)
        {
            // cout << i + 2 << ' ' << 3 * n - 3 * j << '\n';
            char temp = s[i + 2 - 1];
            s[i + 2 - 1] = s[3 * n - 3 * j - 1];
            s[3 * n - 3 * j - 1] = temp;
        }
        // cout << 3 * (n / 2) + 1 << ' ' << 3 * (n / 2) + 2 << '\n';
        char temp = s[3 * (n / 2) + 1 - 1];
        s[3 * (n / 2) + 1 - 1] = s[3 * (n / 2) + 2 - 1];
        s[3 * (n / 2) + 2 - 1] = temp;
    }
    else
    {
        for (int i = 0,j = 0; i < 3*(n / 2); i+=3,j++)
        {
            // cout << i + 2 << ' ' << 3 * n - 3 * j << '\n';
            char temp = s[i + 2 - 1];
            s[i + 2 - 1] = s[3 * n - 3 * j - 1];
            s[3 * n - 3 * j - 1] = temp;
        }
    }
    for(char x:s){
        fprintf(fp_w,"%c",x);
    }
    fprintf(fp_w,"\n");
}

int main(int argc, char const *argv[])
{
    // int t;
    // cin >> t;
    fp_w=fopen("op.txt","w");
    for (int i = 0; i < 10000; i++)
    {
        solve(i);
    }
    return 0;
}
