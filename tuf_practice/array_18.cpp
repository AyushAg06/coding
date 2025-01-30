// two sum problem using hashing and map data structure
#include<bits/stdc++.h>
using namespace std;
vector<int> twosum(vector<int>&nums,int target)
{
    unordered_map<int,int>mpp;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        int complement=target-nums[i];
        if(mpp.find(complement)!=mpp.end())
        {
            return {mpp[complement],i};
        }
        mpp[nums[i]]=i;
    }
    return {};
}
int main()
{
    int n,target;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<"Enter the target value: "<<endl;
    cin>>target;
    vector<int>ans=twosum(nums,target);
    cout<<"The indices of the two numbers are: "<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}