#include<bits/stdc++.h>
using namespace std;
vector<int>previoussmallerelement(vector<int>nums)
{
    stack<int>st;
    int n=nums.size();
    vector<int>ans(n);
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && st.top()>=nums[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            ans[i]=-1;
        }
        else
        {
            ans[i]=st.top();
        }
        st.push(nums[i]);
    }
    return ans;
}
int main()
{
    vector<int>nums={4,5,2,10,8};
    vector<int>ans=previoussmallerelement(nums);
    for(auto it:ans)
    {
        cout<<it<<",";
    }
    return 0;
}