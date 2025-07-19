#include<bits/stdc++.h>
using namespace std;
string vtoc(string s)
{
    vector<char>vawels;
    vector<char>constant;
    string ans="";
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ||
        s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
        {
            vawels.push_back(s[i]);
        }
        else{
            constant.push_back(s[i]);
        }
    }
    int v=0,c=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            ans+=constant[c];
            c++;
        }
        else{
            ans+=vawels[v];
            v++;
        }
    }
    return ans;
}
int main()
{
    string s="ayush";
    cout<<vtoc(s);
    return 0;
}
