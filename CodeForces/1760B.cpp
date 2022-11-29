#include<bits/stdc++.h>
using namespace std;

int solve(){
    int len;
    cin>>len;
    string s;
    cin>>s;
    int maxAscii=-1;
    for(char x:s){
        if((int)x>maxAscii)
            maxAscii=(int)x;
    }
    return maxAscii-96;
}

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<solve()<<'\n';
    }
    return 0;
}
