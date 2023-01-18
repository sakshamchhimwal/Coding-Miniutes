#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int numberOfSolns=0;
    int numberOfPPL=0;
    if(arr[0]!=0){
        numberOfSolns++;
    }
    for(int i=0;i<n;i++){
        numberOfPPL=i+1;
        if(numberOfPPL>arr[i]){
            if(i<n-1 && numberOfPPL<arr[i+1]) numberOfSolns++;
            if(i==n-1) numberOfSolns++;
        }
    }
    return numberOfSolns;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<solve()<<'\n';
    }
}