#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin>>n; cin>>k;
    string s;
    cin>>s;
    int diff=n-k;
    if(diff<k){
        for(int i=diff;i>0;i--){
            cout<<"RIGHT\n";
        }
        for(int i=n;i>0;i--){
            cout<<"PRINT "<<s[i-1]<<'\n';
            if(i!=1) cout<<"LEFT\n";
        }
    }else{
        for(int i=k-1;i>0;i--){
            cout<<"LEFT\n";
        }
        for(int i=0;i<n;i++){
            cout<<"PRINT "<<s[i]<<'\n';
            if(i!=n-1) cout<<"RIGHT\n";
        }
    }
}

int main(){
    solve();
}