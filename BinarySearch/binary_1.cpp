// the process to search in a sorted array is called binary search.
#include<bits/stdc++.h>
using namespace std;
int BinarySearch(vector<int>&nums,int target)
{
    int n=nums.size();
    int low=0;
    int high=n-1; 
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
        else if (nums[mid]<target)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}
int main()
{
    vector<int>nums={1,2,3,4,5,6,7,8,9,10};
    int target=5;
    cout<<BinarySearch(nums,target)<<endl;
    return 0;
}
// time complexity: O(logn)
// space complexity: O(1)