#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    int i =-1;
    for(char x : s){
        i++;
        int c = 0;
        for(char y : s){
            if(x==y)c++;
        }
        if(c==1){
            cout<< i;
            return i;
        }
    }
    return -1;
}
