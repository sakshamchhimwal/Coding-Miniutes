#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string modifyString(string s) {
        vector<int> result;
        char prev,next;
        for(int i=0;i<s.size();i++){
            if(s[i]=='?'){
                if(i>0 && i<s.size()-1){
                    prev=s[i-1];
                    (i+1)<s.size()?next=s[i+1]:next='?';
                    if(next!='?'){
                        int start=97;
                        while (1){
                            if(start!=(int)next && start!=(int)prev && start<118)break;
                            start++;
                        }
                        s[i]=(char)start;
                    }else{
                        prev!='z'?s[i]=(char)((int)prev+1):s[i]=(char)((int)prev-1);
                    }
                }else if(i==0){
                    (i+1)<s.size()?next=s[i+1]:next='?';
                    if(next=='?'){
                        s[i]='a';
                    }else{
                    next=='z'?s[i]=(char)((int)next-1):s[i]=(char)((int)next+1);
                    }
                }else{
                    prev=s[i-1];
                    prev=='z'?s[i]=(char)((int)prev-1):s[i]=(char)((int)prev+1);
                }
            }
        }
        return s; 
    }
};

int main(int argc, char const *argv[])
{
    Solution soln;
    string s=soln.modifyString("?");
    cout<<s;
    return 0;
}
