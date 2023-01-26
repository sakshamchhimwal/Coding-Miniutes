#include<bits/stdc++.h>
using namespace std;

void solve(){
    double n;
    cin>>n;
    if((int)n%2==0){
        cout<<"YES"<<'\n';
        for(int i=0;i<(int)n;i++){
            if(i%2==0){
                cout<<"1 ";
            }else{
                cout<<"-1 ";
            }
        }
        cout<<'\n';
    }else{
        if(n==3){
            cout<<"NO \n";
        }else{
            cout<<"YES"<<'\n';
            int x = ceil(n/2)-1;
            int y = -(x-1);
            for(int i=0;i<(int)n;i++){
                if(i%2==0){
                    cout<<y<<" ";
                }else{
                    cout<<x<<" ";
                }
            }
            cout<<'\n';
        }
    }
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
}