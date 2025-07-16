#include<bits/stdc++.h>
using namespace std;
class MinStack
{
    stack<pair<int,int>>st;
    public:
        void push(int val)
        {
            if(st.empty())
            {
                st.push({val,val});
            }
            else
            {
                st.push({val,min(val,st.top().second)});
            }
        }
        void pop()
        {
            st.pop();
        }
        int top()
        {
            return st.top().first;
        }
        int getmin()
        {
            return st.top().second;
        }
};
int main()
{
    MinStack s;
    s.push(12);
    s.push(15);
    s.push(10);
    cout<<"MINIMUM:-"<<s.getmin()<<endl;
    s.pop();
    cout<<"TOP:-"<<s.top()<<endl;
    cout<<"MINIMUM:-"<<s.getmin();
    return 0;
}