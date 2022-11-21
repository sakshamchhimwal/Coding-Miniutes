#include<bits/stdc++.h>
using namespace std;

int solver(){
    string x;
    cin >> x;
    char prev='/';
    for(char c : x){
        if(c!='Y' && c!='e' && c!='s'){
            return 0;
        }
        if(prev=='/'){
            prev=c;
        }else{
            switch(prev){
                case 'Y':
                    if(c!='e'){
                        
                        return 0;
                    }
                    prev = c;
                    break;
                case 'e':
                    if(c!='s'){
                        
                        return 0;
                    }
                    prev = c;
                    break;
                case 's':
                    if(c!='Y'){
                        
                        return 0;
                    }
                    prev = c;
                    break;
                default:
                    return 0;
            }
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        if(solver()){
            cout<<"\tYES\n";
        }else{
            cout<<"\tNO\n";
        }
    }
    return 0;
}
