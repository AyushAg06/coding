// find out the amount of time a array is rotated in a rotated sorted array(contain duplicates) using binary search
#include<bits/stdc++.h>
using namespace std;
int RotatedArray(vector<int>&nums)
{
    int n=nums.size();
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[low]==nums[mid] && nums[mid]==nums[high])
        {
            low++;
            high--;
        }
        else if(nums[low]<=nums[mid])
        {
            return low;
        }
        else if(nums[mid]<=nums[high])
        {
            return mid;
        }
    }
    return -1;
}
int main()
{
    vector<int>nums={2,5,6,0,0,1,2};
    int result=RotatedArray(nums);
    cout<<"Amount of time array is rotated:-"<<result<<endl;
    return 0;
}