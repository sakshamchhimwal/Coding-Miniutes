#include<bits/stdc++.h>
using namespace std;

int numberOfWays(int n){
    int answer=0;
    if(n==1){
        return 1;
    }
    for(int i=1;i<n;i++){
        answer=answer+numberOfWays(i);
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    cout<<numberOfWays(7);
    return 0;
}
