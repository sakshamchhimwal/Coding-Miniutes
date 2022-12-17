#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> revPol;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens.at(i) != "+" && tokens.at(i) != "-" && tokens.at(i) != "*" && tokens.at(i) != "/")
            {
                string s = tokens.at(i);
                int x = stoi(s);
                revPol.push(x);
            }
            else
            {
                if (tokens.at(i) == "+")
                {
                    int a, b;
                    a = revPol.top();
                    revPol.pop();
                    b = revPol.top();
                    revPol.pop();
                    revPol.push(a + b);
                }
                else if (tokens.at(i) == "-")
                {
                    int a, b;
                    a = revPol.top();
                    revPol.pop();
                    b = revPol.top();
                    revPol.pop();
                    revPol.push(a - b);
                }
                else if (tokens.at(i) == "*")
                {
                    int a, b;
                    a = revPol.top();
                    revPol.pop();
                    b = revPol.top();
                    revPol.pop();
                    revPol.push(a * b);
                }
                else if (tokens.at(i) == "/")
                {
                    int a, b;
                    a = revPol.top();
                    revPol.pop();
                    b = revPol.top();
                    revPol.pop();
                    revPol.push(a / b);
                }
                else
                {
                    continue;
                }
            }
        }
        return revPol.top();
    }
};

int main(int argc, char const *argv[])
{
    vector<string> tokens = {"4", "13", "5", "/", "+"};
    Solution newSol;
    cout << newSol.evalRPN(tokens);
    return 0;
}
