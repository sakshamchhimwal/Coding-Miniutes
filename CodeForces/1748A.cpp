#include<bits/stdc++.h>
using namespace std;


int solve(){
    int n;
    cin>>n;
    if(n%2==0){
        return n/2;
    }else{
        return n/2+1;
    }
}

int main(int argc, char const *argv[])
{
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<solve()<<'\n';
    }    
    return 0;
}
