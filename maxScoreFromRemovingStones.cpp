#include<bits/stdc++.h>
using namespace std;

int maximumScore(int a, int b, int c) {
    vector<int> arr={a,b,c};
    sort(arr.begin(),arr.end());
    a=arr[0];
    b=arr[1];
    c=arr[2];
    if(c>=a+b){
        return a+b;
    }else{
        return c;
    }
}

int main(){
    cout<<maximumScore(2,4,6);
}