#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    unordered_map<char,int> wordMap;
    for(int i=0;i<n;i++){
        if(wordMap.find(s.at(i))==wordMap.end()){
            wordMap[s.at(i)]=1;
        }else{
            wordMap[s.at(i)]+=1;
        }
    }
    int maxFreq=0;
    for(auto x:wordMap){
        if(x.second>maxFreq){
            maxFreq=x.second;
        }
    }
    
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
}