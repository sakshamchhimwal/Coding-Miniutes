#include<bits/stdc++.h>
using namespace std;

int tsp(vector<vector<int>> distance,int checkVisit,int currentCity,int numberOfCity){
    if(checkVisit==(1<<numberOfCity)-1){
        return distance[currentCity][0];//distance b/w current city and startcity.
    }
    int ans = INT_MAX;
    for(int choice=0;choice<numberOfCity;choice++){
        if(!(checkVisit & (1<<choice))){
            int dis = distance[currentCity][choice] +
        }
    }
}