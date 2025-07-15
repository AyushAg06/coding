#include<bits/stdc++.h>
using namespace std;
string prefixtoinfix(string &s)
{
    int i=s.size()-1;
    stack<string>st;
    while(i>=0)
    {
        if((s[i]>='A'&&s[i]<='Z')||
        (s[i]>='a' && s[i]<='z')||
        (s[i]>='0' && s[i]<='9'))
        {
            string op(1,s[i]);
            st.push(op);
        }
        else
        {
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string t3='('+t1+s[i]+t2+')';
            st.push(t3);
        }
        i--;
    }
    return st.top();
}
int main()
{
    string s="*+PQ-MN";
    cout<<prefixtoinfix(s);
    return 0;
}