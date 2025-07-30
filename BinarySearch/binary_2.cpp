// binary search using recurrsion
#include<bits/stdc++.h>
using namespace std;
int BinarySearch(vector<int>&nums,int target,int low,int high)
{
    if(low>high)
    {
        return -1;
    }
    int mid=(low+high)/2;
    if(nums[mid]==target)
    {
        return mid;
    }
    else if(nums[mid]<target)
    {
        return BinarySearch(nums,target,mid+1,high);
    }
    else
    {
        return BinarySearch(nums,target,low,mid-1);
    }
}
int main()
{
    vector<int>nums={1,2,3,4,5,6,7,8,9,10};
    int target=5;
    cout<<BinarySearch(nums,target,0,nums.size()-1)<<endl;
    return 0;
}
// time complexity: O(logn)
// space complexity: O(logn)