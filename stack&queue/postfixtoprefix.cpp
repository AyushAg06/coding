#include<bits/stdc++.h>
using namespace std;
string postfixtoprefix(string s)
{
    int i=0,n=s.size();
    stack<string>st;
    while(i<n)
    {
        if((s[i]>='A' && s[i]<='Z')||
        (s[i]>='a' && s[i]<='z')||
        (s[i]>='0' && s[i]<='9'))
        {
            string op(1,s[i]);
            st.push(op);
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            st.push(s[i]+t2+t1);
        }
        i++;
    }
    return st.top();
}
int main()
{
    string s="AB-DE+F*/";
    cout<<postfixtoprefix(s);
    return 0;
}