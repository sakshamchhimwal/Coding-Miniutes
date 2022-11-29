#include<bits/stdc++.h>
using namespace std;


long long int solve(){
    string s;
    long long int l;
    cin>>l;
    cin >> s;
    long long int tx=0,x=0,y=0,ty=0;
    long long int maxNum=-100;
    for(long long int i=0;i<l;){
        while(s[i]=='0'){
            i++;
            x++;
            tx++;
        }
        while(s[i]=='1'){
            i++;
            y++;
            ty++;
        }
        long long int sx = x*x;
        long long int sy = y*y;
        long long int sb = tx*ty;
        if (maxNum < max({sx, sy, sb})){
            maxNum = max({sx, sy, sb});
        }
        x=0;y=0;
    }
    return maxNum;
}

int main(int argc, char const *argv[])
{
    long long int t=0;
    cin>>t;
    for(long long int i=0;i<t;i++){
        long long int k=solve();
        cout<<k<<'\n';
    }
    return 0;
}
