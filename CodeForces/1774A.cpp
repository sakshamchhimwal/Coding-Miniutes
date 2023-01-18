#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;  cin>>n;
    string num;    cin>>num;
    stack<char> numStack;
    for(int i=num.size()-1;i>=0;i--){
        numStack.push(num[i]);
    }
    bool isWasOne=0;
    if(numStack.top()=='1'){
        isWasOne=1;
        numStack.pop();
    }else{
        numStack.pop();
    }
    while(!numStack.empty()){
        if(numStack.top()=='1' && !isWasOne){
            cout<<'+';
            isWasOne=!isWasOne;
        }else if(numStack.top()=='1' && isWasOne){
            cout<<'-';
            isWasOne=!isWasOne;
        }else{
            cout<<'+';
        }
        numStack.pop();
    }
    cout<<'\n';
}

int main(){
    int t;
    cin>>t;
    for(;t>0;t--){
        solve();
    }
}