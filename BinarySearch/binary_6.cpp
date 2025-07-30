// find floor ans ceil of a number in a sorted array using binary search
#include<bits/stdc++.h>
using namespace std;
int floor(vector<int>&nums,int target)
{
    int n=nums.size();
    int low=0,high=n-1,ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]<=target)
        {
            ans=nums[mid];
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int Ceil(vector<int>&nums,int target)
{
    int n=nums.size();
    int low=0,high=n-1,ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]>=target)
        {
            ans=nums[mid];
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}
int main()
{
    vector<int>nums={1,2,8,10,10,12,19};
    int target=5;
    cout<<"Floor:-"<<floor(nums,target)<<endl;
    cout<<"Ceil:-"<<Ceil(nums,target)<<endl;
    return 0;
}
// Time Complexity: O(logn)
// Space Complexity: O(1)