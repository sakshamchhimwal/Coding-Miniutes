#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int oddCounter=0;
    int evenCounter=0;
    vector<int> oddIndex ={};
    vector<int> evenIndex = {};
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]%2==0){
            evenCounter+=1;
            evenIndex.push_back(i);
        }else{
            oddCounter+=1;
            oddIndex.push_back(i);
        }
        
       
    }
    if(oddCounter>=3){
            cout<<"YES\n";
            for(int j=0;j<3;j++){
                cout<<oddIndex[j]+1<<" ";
            }
            cout<<'\n';
            return;
        }
     if(oddCounter>=1 && evenCounter>=2){
            vector<int> x = {};
            for(int j=0;j<2;j++){
                x.push_back(evenIndex[j]);
            }
            x.push_back(oddIndex[0]);
            sort(x.begin(),x.end());
            cout<<"YES\n";
            for(int j=0;j<3;j++){
                cout<<x[j]+1<<" ";
            }
            cout<<'\n';
            return;
        }
    cout<<"NO\n";
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
}