#include<bits/stdc++.h>
using namespace std;
class StockSpanner
{
    public:
        int ind=-1;
        stack<pair<int,int>>st;
        StockSpanner()
        {
            ind=-1;
        }
        int next(int data)
        {
            ind=ind+1;
            while(!st.empty() && st.top().first<=data)
            {
                st.pop();
            }
            int ans=ind-(st.empty()?-1:st.top().second);
            st.push({data,ind});
            return ans;
        }
};
int main()
{
    StockSpanner ss= StockSpanner();
    cout<<ss.next(7)<<endl;
    cout<<ss.next(2)<<endl;
    cout<<ss.next(1)<<endl;
    cout<<ss.next(3)<<endl;
    cout<<ss.next(3)<<endl;
    cout<<ss.next(1)<<endl;
    cout<<ss.next(8)<<endl;
    return 0;
}