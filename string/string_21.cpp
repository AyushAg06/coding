// check if the string is rotated or not 
// input=s-abcde,goal-cdeab 
// output-true 
#include<bits/stdc++.h>
using namespace std;
bool  rotated(string s,string goal)
{
    if(s.length()!=goal.length())
    {
        return false;
    }
    for(int i=0;i<s.size();i++)
    {
        char first=s[0];
        s.erase(s.begin());
        s.push_back(first);
        if(s==goal)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    string s={"abcde"};
    string goal={"cdeab"};
    cout<<rotated(s,goal);
    return 0;
}