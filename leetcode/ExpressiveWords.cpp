#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int expressiveWords(string s, vector<string>& words){
        int result=0;
        for(string w:words){
            int lastCheckIndex=0;
            bool correct=true;
            for(int i=0;i<w.size();i++){
                char curr=w[i];
                int counter=1;
                while(w[i+1]==w[i]){
                    i++;
                    counter++;
                }
                int tell=lastCheckIndex;
                while(s[tell]==curr){
                    tell++;
                }
                if(tell==lastCheckIndex){
                    correct=false;
                    break;
                }else{
                    if(counter>(tell-lastCheckIndex)){
                        correct=false;
                        break;
                    }
                    if(counter<3 && counter!=(tell-lastCheckIndex) && (tell-lastCheckIndex)<3){
                        correct=false;
                        break;
                    }
                    if(i==w.size()-1 && tell!=s.size()){
                        correct=false;
                        break;
                    }
                    lastCheckIndex=tell;
                } 
            }
            if(correct)
                    result++;
        }
        return result;
    }
};


int main(){
    string s="abcd";
    vector<string> vec={"abc"};
    Solution soln;
    cout<<soln.expressiveWords(s,vec);
}