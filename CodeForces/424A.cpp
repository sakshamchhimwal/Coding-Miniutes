#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int arr[]={0,0};
    for(char x:s){
        if(x=='x') arr[0]++;
        if(x=='X') arr[1]++;
    }
    int diff1=arr[0]-arr[1];
    int diff2=arr[1]-arr[0];
    if(diff1==0 && diff2==0){
        cout<<"0\n"<<s;
        return;
    }
    if(diff1>0){
        int counter=0;
        for(int i=0;i<n && counter<(diff1+1)/2;i++){
            if(s[i]=='x'){
                s[i]='X';
                counter++;
            }
        }
        cout<<counter<<endl<<s;
    }else{
        int counter=0;
        for(int i=0;i<s.size() && counter<(diff2+1)/2;i++){
            if(s[i]=='X'){
                s[i]='x';
                counter++;
            }
        }
        cout<<counter<<endl<<s;
    }
}

int main(){
    solve();
}