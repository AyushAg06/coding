#include<bits/stdc++.h>
using namespace std;
vector<int>nextgreaterelement(vector<int>nums)
{
    int n=nums.size();
    vector<int>ans(n);
    stack<int>st;
    for(int i=2*n-1;i>=0;i--)
    {
        while(!st.empty() && st.top()<=nums[i%n])
        {
            st.pop();
        }
        if(i<n)
        {
            ans[i]=st.empty()?-1:st.top();
        }
        st.push(nums[i%n]);
    }
    return ans;
}
int main()
{
    vector<int>nums={2,10,12,1,11};
    vector<int>ans=nextgreaterelement(nums);
    for(auto it:ans)
    {
        cout<<it<<",";
    }
    return 0;
}