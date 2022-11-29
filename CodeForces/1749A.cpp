#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n,m;
    cin>>n;
    cin>>m;
    int sum=0;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a;
        cin>>b;
        sum+=a;
    }
    if(sum<((n*(n+1))/2)){
        return 1;
    }
    return 0;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        if(solve()){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}