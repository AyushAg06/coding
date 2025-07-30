// find the minimum element in a rotated sorted array using binary search
#include<bits/stdc++.h>
using namespace std;
vector<int>Search(vector<int>&nums)
{
    int n=nums.size();
    int low=0,high=n-1;
    int ans=INT_MAX;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[low]<=nums[mid])
        {
            ans=min(ans,nums[low]);
            low=mid+1;
        }
        else if(nums[mid]<=nums[high])
        {
            ans=min(ans,nums[mid]);
            high=mid-1;
        }
    }
    return {ans};
}
int main()
{
    vector<int>nums={3,4,5,1,2};
    vector<int>result=Search(nums);
    cout<<"Minimum Element:-"<<result[0]<<endl;
    return 0;
}