#include<bits/stdc++.h>
using namespace std;


void makeBeautyMatrix(int n,int i,int j,vector<int> &consumedDiff,vector<int> &consumedNums,vector<vector<int>> &resMatirx){
    if(i==0 && j==0){
        resMatirx[0][0]=1;
        consumedNums[1]=1;
    }
    if(i==0 && j!=0){
        int maxDiff = consumedDiff[consumedDiff.size()-1];
        int possibleNum1 = maxDiff+resMatirx[0][j-1];
        int possibleNum2 = abs(maxDiff-resMatirx[0][j-1]);
        bool test1=1,test2=1;
        if(possibleNum1>0 &&  possibleNum1<=n*n){
            int loc = consumedDiff.size()-1;
            while(test1){
                possibleNum1 = maxDiff+resMatirx[0][j-1];
                if(!consumedNums[possibleNum1]){
                    resMatirx[0][j]=possibleNum1;
                    consumedNums[possibleNum1]=1;
                    consumedDiff.erase(consumedDiff.begin()+loc);
                    break;
                }else{
                    loc-=1;
                    maxDiff=consumedDiff[loc];
                    if(loc<=0){
                        loc=consumedDiff.size()-1;
                        maxDiff=consumedDiff[loc];
                        test1=0;
                    }
                }
            }
        }
        if(possibleNum2>0 && possibleNum2<=n*n && resMatirx[0][j]==-1){
            int loc = consumedDiff.size()-1;
            while(test2){
                possibleNum2 = abs(maxDiff-resMatirx[0][j-1]);
                if(!consumedNums[possibleNum2]){
                    resMatirx[0][j]=possibleNum2;
                    consumedNums[possibleNum2]=1;
                    consumedDiff.erase(consumedDiff.begin()+loc);
                    break;
                }else{
                    loc-=1;
                    maxDiff=consumedDiff[loc];
                    if(loc<=0){
                        loc=consumedDiff.size()-1;
                        maxDiff=consumedDiff[loc];
                        test2=0;
                    }
                }
            }
        }
    }
    for(int cols = 1;cols<n;cols++){
        int maxDiff = consumedDiff[consumedDiff.size()-1];
        int possibleNum1 = maxDiff+resMatirx[cols-1][j];
        int possibleNum2 = abs(maxDiff-resMatirx[cols-1][j]);
        bool test1=1,test2=1;
        if(possibleNum1>0 &&  possibleNum1<=n*n){
            int loc = consumedDiff.size()-1;
            while(test1){
                possibleNum1 = maxDiff+resMatirx[cols-1][j];
                if(!consumedNums[possibleNum1]){
                    resMatirx[cols][j]=possibleNum1;
                    consumedNums[possibleNum1]=1;
                    consumedDiff.erase(consumedDiff.begin()+loc);
                    break;
                }else{
                    loc-=1;
                    maxDiff=consumedDiff[loc];
                    if(loc<=0){
                        loc=consumedDiff.size()-1;
                        maxDiff=consumedDiff[loc];
                        test1=0;
                    }
                }
            }
        }
        if(possibleNum2>0 && possibleNum2<=n*n && resMatirx[cols][j]==-1){
            int loc = consumedDiff.size()-1;
            while(test2){
                possibleNum2 = abs(maxDiff-resMatirx[cols-1][j]);
                if(!consumedNums[possibleNum2]){
                    resMatirx[cols][j]=possibleNum2;
                    consumedNums[possibleNum2]=1;
                    consumedDiff.erase(consumedDiff.begin()+loc);
                    break;
                }else{
                    loc-=1;
                    maxDiff=consumedDiff[loc];
                    if(loc<=0){
                        loc=consumedDiff.size()-1;
                        maxDiff=consumedDiff[loc];
                        test2=0;
                    }
                }
            }
        }
        if(resMatirx[cols][j]==-1){
            for(int i=1;i<consumedNums.size();i++){
                if(!consumedNums[i]){
                    resMatirx[cols][j]=i;
                    consumedNums[i]=1;
                    break;
                }
            }
        }
    }
    if(j+1<n){
        makeBeautyMatrix(n,i,j+1,consumedDiff,consumedNums,resMatirx);
    }else{
        return;
    }
}

void solve(){
    int n;
    cin>>n;
    int maxNum = n*n;
    vector<int> consumedDiff(maxNum,0);
    vector<int> consumedNums(maxNum+1,0);
    for(int i=0;i<maxNum;i++){
        consumedDiff[i]=i;
    }
    vector<vector<int>> resMatirx(n,vector<int> (n,-1));
    makeBeautyMatrix(n,0,0,consumedDiff,consumedNums,resMatirx);
    for(vector<int> x:resMatirx){
        for(int y:x){
            cout<<y<<" ";
        }
        cout<<'\n';
    }
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
}