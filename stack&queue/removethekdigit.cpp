#include<bits/stdc++.h>
using namespace std;
string removekdigit(string s,int k)
{
    stack<char>st;
    for(int i=0;i<s.size();i++)
    {
        while(!st.empty() && (st.top()-'0')>(s[i]-'0') && k>0)
        {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }
    while(k>0)
    {
        st.pop();
        k--;
    }
    string rev="";
    while(!st.empty())
    {
        rev.push_back(st.top());
        st.pop();
    }
    reverse(rev.begin(),rev.end());
    int i=0;
    while(i<rev.size() && rev[i]==0)
    {
        i++;
    }
    rev=rev.substr(i);
    return rev.empty()?"0":rev;
}
int main()
{
    string s="1432219";
    int k=3;
    cout<<removekdigit(s,k);
    return 0;
}