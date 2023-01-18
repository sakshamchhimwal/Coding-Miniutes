#include <bits/stdc++.h>
using namespace std;
int charToInt(char c)
{
    return (int)c - 48;
}
// string getHint(string secret, string guess) {
//     int strSize = secret.size();
//     vector<int> freqSecret(10,0);
//     vector<int> freqGuess(10,0);
//     int bulls=0,cows=0;
//     for(int i=0;i<strSize;i++){
//         int gI = charToInt(guess.at(i));
//         int sI = charToInt(secret.at(i));
//         freqSecret[sI]+=1;
//         freqGuess[gI]+=1;
//     }
//     for (int i = 0; i < strSize; i++){
//         int gI = charToInt(guess.at(i));
//         int sI = charToInt(secret.at(i));
//         if(secret[i]==guess[i]){
//             bulls+=1;
//             freqSecret[sI]-=1;
//             freqGuess[gI]-=1;
//         }else{
//             if(freqSecret[gI]>0){
//                 cows+=1;
//                 freqSecret[gI]-=1;
//                 freqGuess[gI]-=1;
//             }
//             if(freqGuess[sI]>0){
//                 cows+=1;
//                 freqGuess[sI]-=1;
//                 freqSecret[sI]-=1;
//             }
//         }
//     }
//     return to_string(bulls)+"A"+to_string(cows)+"B";
string getHint(string secret, string guess)
{
    int strSize = secret.size();
    vector<int> freqSecret(10, 0);
    vector<int> freqGuess(10, 0);
    int bulls = 0, cows = 0;
    for (int i = 0; i < strSize; i++)
    {
        int gI = charToInt(guess.at(i));
        int sI = charToInt(secret.at(i));
        freqSecret[sI] += 1;
        freqGuess[gI] += 1;
    }
    for (int i = 0; i < strSize; i++)
    {
        int gI = charToInt(guess.at(i));
        int sI = charToInt(secret.at(i));
        if (secret[i] == guess[i])
        {
            bulls += 1;
            freqSecret[sI] -= 1;
            freqGuess[gI] -= 1;
            secret.erase(secret.begin()+i);
            guess.erase(guess.begin()+i);
            strSize=secret.size();
            i-=1;
        }
    }
    for (int i = 0; i < strSize; i++)
    {
        int gI = charToInt(guess.at(i));
        int sI = charToInt(secret.at(i));
        if (freqSecret[gI] > 0)
        {
            cows += 1;
            freqSecret[gI] -= 1;
            freqGuess[gI] -= 1;
        }
        if (freqGuess[sI] > 0)
        {
            cows += 1;
            freqGuess[sI] -= 1;
            freqSecret[sI] -= 1;
        }
    }
    return to_string(bulls) + "A" + to_string(cows) + "B";
}


int main()
{
    cout << getHint("1123", "0111");
}