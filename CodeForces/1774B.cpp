#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long int n,m,k;
    cin>>n;cin>>m;cin>>k;
    long long int arr[m];
    sort(arr,arr+m);
    while (arr[m-1]){
        int startIndex=0;
        int isZero=0;
        for(int i=startIndex;i<(startIndex+k)%m;i++){
            if(arr[i]!=0) arr[i]-=1;
            else isZero++;
        }
        if(arr[startIndex]==0) startIndex+=1;
    }
    
}

int main(){
    int t;
    cin>>t;
    for(;t>0;t--){
        solve();
    }
}