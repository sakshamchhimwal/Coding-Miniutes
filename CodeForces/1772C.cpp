#include<bits/stdc++.h>
using namespace std;

int getSamllestNonConsumed(vector<int> &consumed,int lastInt){
    for(int i=0;i<consumed.size();i++){
        if(!consumed[i] && lastInt<i+1){
            return i+1;
            consumed[i]=1;
        }
    }
    return -1;
}

void solve(){ 
    int k,n;
    cin>>k;
    cin>>n;
    int arr[k];
    arr[0]=1;
    vector<int> consumed(n,0);
    int currDiff=1;
    for(int i=1;i<k;i++){
        if(arr[i-1]+currDiff<=n && n-arr[i-1]-currDiff>=k-i-1){
            arr[i]=arr[i-1]+currDiff;
            consumed[arr[i]-1]=1;
            currDiff+=1;
        }else if(arr[i-1]+currDiff<=n && n-arr[i-1]-currDiff<k-i){
            currDiff>1?currDiff-=1:currDiff-=0;
            i-=1;
        }else{
            arr[i]=getSamllestNonConsumed(consumed,arr[i-1]);
        }
    }
    for(int i=0;i<k;i++){
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
        solve();
}