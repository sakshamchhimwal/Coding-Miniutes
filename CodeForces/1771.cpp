#include<bits/stdc++.h>
using namespace std;

int solve(){
    unordered_map<int,vector<int>> numMap;
    int n;
    cin>>n;
    int minNum=INT_MAX,maxNum=INT_MIN;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        numMap[num].push_back(i);
        if(num<minNum){
            minNum=num;
        }
        if(num>maxNum){
            num=maxNum;
        }
    }
    int vals=0;
    int maxDiff = maxNum-minNum;
    for(auto i : numMap){
        int num1=maxDiff-i.first;
        vals+=i.second * numMap[num1].size();
    }
    return vals;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<solve();
    }
}