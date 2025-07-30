#include<bits/stdc++.h>
using namespace std;
vector<int>nextgreaterelement(vector<int>&nums1,vector<int>&nums2)
{
    stack<int>st;
    unordered_map<int,int>mpp;
    for(int i=nums2.size()-1;i>=0;i--)
    {
        while(!st.empty() && st.top()<=nums2[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            mpp[nums2[i]]=-1;
        }
        else
        {
            mpp[nums2[i]]=st.top();
        }
        st.push(nums2[i]);
    }
    vector<int>res;
    for(int i=0;i<nums1.size();i++)
    {
        res.push_back(mpp[nums1[i]]);
    }
    return res;
}
int main()
{
    vector<int>nums1={4,1,2};
    vector<int>nums2={1,3,4,2};
    vector<int>nums3=nextgreaterelement(nums1,nums2);
    for(auto it:nums3)
    {
        cout<<it<<",";
    }
    return 0;
}