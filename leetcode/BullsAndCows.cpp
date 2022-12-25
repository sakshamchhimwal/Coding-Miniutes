#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int charToInt(char c){
        return (int)c-48;
    }
    string getHint(string secret, string guess) {
        int bull=0,cow=0;
        unordered_map<int,vector<int>> secMap;
        unordered_map<int,vector<int>> gusMap;
        for(int i=0;i<10;i++){
            secMap[i]={};
            gusMap[i]={};
        }
        int arrx[]={0,0,0,0,0,0,0,0,0,0};
        int arry[]={0,0,0,0,0,0,0,0,0,0};
        for(int i=0;i<secret.size();i++){
            int x = charToInt(secret.at(i));
            secMap[x].push_back(i);
            arrx[x]+=1;
        }
        for(int i=0;i<guess.size();i++){
            int x = charToInt(guess.at(i));
            gusMap[x].push_back(i);
            arry[x]+=1;
        }
        for(auto x:gusMap){
            vector<int> vec1=secMap[x.first];
            vector<int> vec2=x.second;
            if(vec1.size()!=0){
                for(int i=0;i<vec2.size();i++){
                    int findIndex=vec2[i];
                    int isFound=0;
                    for(int j=0;j<vec1.size();j++){
                        if(vec1[j]==findIndex){
                            isFound++;
                            bull++;
                            if(arrx[x.first]==0 || arry[x.first]==0){
                                cow--;
                            }else{
                                arrx[x.first]-=1;
                                arry[x.first]-=1;
                            }
                            break;
                        }
                    }
                    if(!isFound && arrx[x.first]!=0 && arry[x.first]!=0){
                        cow++;
                        arrx[x.first]-=1;
                        arry[x.first]-=1;
                    }
                }
            }
        }
        return to_string(bull)+"A"+to_string(cow)+"B";
    }
};

int main(){
    cout<<"Running\n";
    Solution soln;
    cout<<soln.getHint("6244988279","3819888600");
}