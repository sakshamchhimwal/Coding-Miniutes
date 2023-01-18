#include<bits/stdc++.h>
using namespace std;

int distributeCandies(vector<int> candies){
   sort(candies.begin(),candies.end());
   int lim =candies.size();
   int typeOfCandies=0;
   for(int i=0;i<lim;i++){
        int curr = candies[i];
        while (i<lim-1 && curr==candies[i+1]){
            i++;
        }
        typeOfCandies++;
   }
   if(typeOfCandies>lim/2){
        return lim/2;
   }else{
    return typeOfCandies;
   }
}
int main(){
    cout<<distributeCandies({1,1,2,2,3,3,2,1,4,4,5,7});
}