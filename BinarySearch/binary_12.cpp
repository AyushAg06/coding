// find the element which is appearing once in the array where all other elements are appearing twice using binary search
#include<bits/stdc++.h>
using namespace std;
vector<int>SingleElement(vector<int>&nums)
{
    int n=nums.size();
    int low=0,high=n-1;
    if(n==1)
    {
        return {nums[0]};
    }
    if(nums[0]!=nums[1])
    {
        return {nums[0]};
    }
    if(nums[n-1]!=nums[n-2])
    {
        return {nums[n-1]};
    }
    low=1,high=n-2;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
        {
            return {nums[mid]};
        }
        if((mid%2==1 && nums[mid]==nums[mid-1])||(mid%2==0 && nums[mid]==nums[mid+1]))
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return {-1};
}
int main()
{
    vector<int>nums={1,1,2,2,3,3,4,4,5,5,6};
    vector<int>result=SingleElement(nums);
    if(result[0]==-1)
    {
        cout<<"Element not found"<<endl;
    }
    else
    {
        cout<<"Element found:-"<<result[0]<<endl;
    }
    return 0;
}