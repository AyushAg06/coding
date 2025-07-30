// find the lower bound of a number in a sorted array
#include<bits/stdc++.h>
using namespace std;
int LowerBound(vector<int>&nums,int target)
{
    int n=nums.size();
    int low=0,high=n-1;
    int ans=n;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]>=target)
        {
            ans=mid;
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
    vector<int>nums={1,2,3,4,5,6,7,8,9,10};
    int target=5;
    cout<<LowerBound(nums,target)<<endl;
    return 0;
}
// time complexity: O(logn)
// space complexity: O(1)