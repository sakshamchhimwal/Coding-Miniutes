#include<bits/stdc++.h>
using namespace std;

string sortByFreq(string s){
    int maxFreq=0;
    int len =s.size();
    for(int i=0;i<len;i++){
        int counter=1;
        while (i<len-1 && s[i]==s[i+1]){
            counter++;
            i+=1;
        }
        if(counter>maxFreq)
            maxFreq=counter;
    }
    vector<vector<char>> sortFreqVal(maxFreq,vector<char>());
    for(int i=0;i<len;i++){
        int counter=0;
        while (i<len-1 && s[i]==s[i+1]){
            counter++;
            i+=1;
        }
        for(int j=0;j<counter+1;j++)
            sortFreqVal[counter].push_back(s[i]);
    }
    for(vector<char> x:sortFreqVal){
        for(char c:x)
            cout<<c<<',';
        cout<<'\n';
    }
    cout<<maxFreq;
    int minNumberOfMoves=0;
    int freqToReach=maxFreq;
    for(int i=0;i<maxFreq;i++){
        if(sortFreqVal[i].size()%freqToReach!=0){
            freqToReach-=1;
            continue;
        }else{
            if(i!=freqToReach-1){
                for(int j=0;j<sortFreqVal[i].size();j++){
                    char currChar=sortFreqVal[i][j];
                    for(int k=0;k<freqToReach-1;k++){
                        sortFreqVal[i][j+k]=currChar;
                    }
                    j+=freqToReach-1;
                }
            }
        }
    }
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    sortByFreq(s);
}

int main(){
    // int t;
    // cin>>t;
    // for(int i=0;i<t;i++){
    //     solve();
    // }
    solve();
}