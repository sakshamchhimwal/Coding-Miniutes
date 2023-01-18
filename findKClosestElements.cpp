#include<bits/stdc++.h>
using namespace std;
vector<int> findClosestElements(vector<int> arr, int k, int x) {
    unordered_map<int,vector<int>> diffMap;
    int maxVal = INT_MIN;
    int sizeOfArr = arr.size();
    for(int i=0;i<sizeOfArr;i++){
        int diff = abs(arr[i]-x);
        if(diff>maxVal)
            maxVal=diff;
        diffMap[diff].push_back(arr[i]);
    }
    vector<int> resVec={};
    for(int i=0;i<maxVal+1;i++){
        if(diffMap.find(i)!=diffMap.end()){
            for(int x:diffMap[i]){
                if(k>0){
                    resVec.push_back(x);
                    k-=1;
                }
                else{
                    sort(resVec.begin(),resVec.end());
                    return resVec;
                }
            }
        }
    }
    sort(resVec.begin(),resVec.end());
    return resVec;
}

int main(){
    for(int c:findClosestElements({1,2,3,4,5},4,3)){
        cout<<c<<',';
    }
}