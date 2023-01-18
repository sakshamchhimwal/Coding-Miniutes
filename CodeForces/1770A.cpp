#include<bits/stdc++.h>
using namespace std;

int64_t sum(int arr[],int size){
    int64_t sum=0;
    for(int i=0;i<size;i++)
        sum+=arr[i];
    return sum;
}

int64_t solve(){
    int m,n;
    cin>>m;
    cin>>n;
    int arr1[m];
    int arr2[n];
    for(int i=0;i<m;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++){
        cin>>arr2[i];
    }
    sort(arr1,arr1+m);
    int changeIndex=0;
    for(int i=0;i<n;i++){
        if(arr2[i]>arr1[changeIndex]){
            arr1[changeIndex]=arr2[i];
            changeIndex++;
            changeIndex=changeIndex%m;
        }else{
            if(changeIndex>0 && arr1[changeIndex-1]>arr2[i]){
                arr1[changeIndex]=arr2[i];
            }else{
                changeIndex>0?arr1[changeIndex-1]=arr2[i]:arr1[changeIndex]=arr2[i];
            }
        }
    }
    return sum(arr1,m);
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<solve()<<'\n';
    }
}