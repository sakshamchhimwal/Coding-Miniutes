#include<bits/stdc++.h>
using namespace std;

int solve(){
    string x;
    cin>>x;
    stack<int> s;
    for(char c:x){
        if(c=='Q'){
            s.push(1);
        }else{
            if(!s.empty()){
                s.pop();
            }
        }
    }
    if(!s.empty()){
        return 0;
    }else{
        return 1;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        if(solve()) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
