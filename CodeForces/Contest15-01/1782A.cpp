#include<bits/stdc++.h>
using namespace std;

int solve(){
    int w,d,h;
    cin>>w;cin>>d;cin>>h;
    int a,b,f,g;
    cin>>a;cin>>b;cin>>f;cin>>g;
    int res=0;
    res+=h;
    int bottomViaX = min(a+f,w-a+w-f)+abs(g-b);
    int bottomViaY = min(b+g,d-b+d-g)+abs(a-f);
    res+=min(bottomViaX,bottomViaY);
    return res;
}


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<solve()<<'\n';
    }
}