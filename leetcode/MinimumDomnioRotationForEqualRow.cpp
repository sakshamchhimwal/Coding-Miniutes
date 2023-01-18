#include<bits/stdc++.h>
using namespace std;

//inclusion exclusion used elgantly
int minDominoRotations(vector<int>& A, vector<int>& B) {
    vector<int> countA(7), countB(7), same(7);
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        countA[A[i]]++;
        countB[B[i]]++;
        if (A[i] == B[i])
            same[A[i]]++;
    }
    for (int i  = 1; i < 7; ++i)
        if (countA[i] + countB[i] - same[i] == n)
            return n - max(countA[i], countB[i]);
    return -1;
}

class Solution{
private:
    
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms){
        
    }
};


int main(){
    vector<int> tops={2,1,2,4,2,2};
    vector<int> bottoms={5,2,6,2,3,2};
    Solution soln;
    cout<<soln.minDominoRotations(tops,bottoms);
}