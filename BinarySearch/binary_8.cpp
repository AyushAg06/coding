// search an element in a rotated sorted array using binary search
#include<bits/stdc++.h>
using namespace std;
vector<int>RotatedArray(vector<int>&nums,int target)
{
    int n=nums.size();
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==target)
        {
            return {mid};
        }
        // left part is sorted 
        else if(nums[low]<=nums[mid])
        {
            if(nums[low]<=target && target<=nums[mid])
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        // right part is sorted
        else if(nums[mid]<=nums[high])
        {
            if(nums[mid]<=target && target<=nums[high])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
    }
    return {-1};
}
int main()
{
    vector<int>nums={4,5,6,7,0,1,2};
    int target=0;
    vector<int>result=RotatedArray(nums,target);
    if(result[0]==-1)
    {
        cout<<"Element not found"<<endl;
    }
    else
    {
        cout<<"Element found at index:-"<<result[0]<<endl;
    }
    return 0;
}
// Time Complexity:- O(logn)
// Space Complexity:- O(1)
