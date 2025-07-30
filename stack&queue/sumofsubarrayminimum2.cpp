#include<bits/stdc++.h>
using namespace std;
int sumofsubarrayminimum(vector<int>arr)
{
    int n=arr.size();
    vector<int>nextless(n);
    vector<int>prevless(n);
    stack<int>st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]>arr[i])
        {
            st.pop();
        }
        prevless[i]=st.empty()?i+1:i-st.top();
        st.push(i);
    }
    while(!st.empty())
    {
        st.pop();
    }
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        nextless[i]=st.empty()?n-i:st.top()-i;
        st.push(i);
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+(arr[i]*nextless[i]*prevless[i]);
    }
    return sum;
}
int main()
{
    vector<int>arr={3,1,2,4};
    cout<<sumofsubarrayminimum(arr);
    return 0;
}