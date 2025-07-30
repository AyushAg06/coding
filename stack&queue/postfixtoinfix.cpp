#include<bits/stdc++.h>
using namespace std;
string postfixtoinfix(string s)
{
    int i=0,n=s.size();
    stack<string>st;
    while(i<n)
    {
        if((s[i]>='A'&&s[i]<='Z')||
        (s[i]>='a' && s[i]<='z')||
        (s[i]>='0' && s[i]<='9'))
        {
            string op(1,s[i]);
            st.push(op);
        }
        else{
            string t1="",t2="",t3="";
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();
            t3='('+t1+s[i]+t2+')';
            st.push(t3);
        }
        i++;
    }
    return st.top();
}
int main()
{
    string postfix = "ab+c*";
    cout << "Infix: " << postfixtoinfix(postfix) << endl; // Output: ((a+b)*c)
    return 0;
}