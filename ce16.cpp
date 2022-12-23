#include<bits/stdc++.h>
using namespace std;


int rangeBitwiseAnd(int left, int right) {
    int result=1;
    for(int i=left;i<=right;i++){
        result = (result & i);
    }
    return result;
}

int main(){
    cout<<rangeBitwiseAnd(5,7);
}