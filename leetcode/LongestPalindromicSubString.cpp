#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    string result="";
    int isPall(string str,int leftIndex,int rightIndex){
        string copyS=str;
        char temp=copyS[leftIndex];
        copyS[leftIndex]=copyS[rightIndex];
        copyS[rightIndex]=temp;
        if(str==copyS)
            return true;
        return false;
    }
    void subStr(string str,int leftIndex,int rightIndex){
        bool onRightIncrease;
        bool onLeftIncrease;
        bool onLRIncrease;
        if(leftIndex>0 && rightIndex<str.size() && isPall(str.substr(leftIndex-1,rightIndex+1),leftIndex-1,rightIndex)){
            onLeftIncrease=true;
        }else{
            onLeftIncrease=false;
        }
        if(rightIndex<str.size() && isPall(str.substr(leftIndex,rightIndex+2),leftIndex,rightIndex+1)){
            onRightIncrease=true;
        }else{
            onRightIncrease=false;
        }
    }
public:
    string longestPalindrome(string s){
        subStr(s,0,0);
        return result;
    }
};

int main(){
    Solution soln;
    cout<<soln.longestPalindrome("babad");
}