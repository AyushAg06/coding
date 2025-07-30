#include<bits/stdc++.h>
using namespace std;
bool isvalid(string s)
{
    stack<int>st;
    for(auto it:s)
    {
        if(it=='('||it=='{'||it=='[')
        {
            st.push(it);
        }
        else{
            if(st.empty())
            {
                return false;
            }
            char ch=st.top();
            st.pop();
            if(it=='}'&&ch=='{'||it==']'&&ch=='['||it==')'&&ch=='(')
            {
                continue;
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
}
int main()
{
    string s="(){()[]}";
    if(isvalid(s))
    {
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}