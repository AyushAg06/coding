#include<bits/stdc++.h>
using namespace std;
int maximumsubstring(string s)
{
    int lastseen[3]={-1,-1,-1},count=0;
    for(int i=0;i<s.size();i++)
    {
        lastseen[s[i]-'a']=i;
        if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1)
        {
            count=count+(1+min(lastseen[0],min(lastseen[1],lastseen[2])));
        }
    }
    return count;
}
int main()
{
    string s="abcabc";
    cout<<maximumsubstring(s);
    return 0;
}