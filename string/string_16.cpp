// remove the outermost parenthesis of a given string 
// input="(()()())"
// output="()()()"
#include<bits/stdc++.h>
using namespace std;
string outputstring(string s)
{
    string result;
    int depth=0;
    for(char c:s)
    {
        if(c=='(')
        {
            if(depth>0)
            {
                result+=c;
            }
            depth++;
        }
        else if(c==')')
        {
            depth--;
            if(depth>0)
            {
                result+=c;
            }
        }
    }
    return result;
}
int main()
{
    string s={"(()()())"};
    cout<<outputstring(s);
    return 0;
}