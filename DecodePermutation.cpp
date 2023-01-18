#include<bits/stdc++.h>
using namespace std;


vector<int> decode(vector<int> encoded) {
    int maxNum = encoded.size()+1;
    int tempNum = maxNum;
    int maxBitIndex = 0;
    while (tempNum!=0){
        maxBitIndex+=1;
        tempNum=tempNum>>1;
    }
    for(int x:encoded){
        
    }
}

int main(){
    vector<int> encodeArr;
    encodeArr = {};
    vector<int> decodeArr = decode(encodeArr);
    for(int x:decodeArr)
        cout<<x<<',';
    
}