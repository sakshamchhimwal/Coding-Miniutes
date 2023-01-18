#include<bits/stdc++.h>
using namespace std;

int64_t solve(int64_t n){
    if(n>1){
        return n-1;
    }else{
        return -1;
    }
}

int main(){
    int64_t t;
    cin>>t;
    for(;t>0;t--){
        int64_t n;
        cin>>n;
        cout<<solve(n)<<'\n';
    }
}