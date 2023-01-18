#include<bits/stdc++.h>
using namespace std;

void solve(){
    int t;
    cin>>t;
    int arr[]={0,0,0};
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        arr[n-1]++;
    }
    int reps1=arr[1]+arr[2];
    int reps2=arr[0]+arr[2];
    int reps3=arr[0]+arr[1];
    cout<<min({reps1,reps2,reps3});
}

int main(){
    solve();
}