// find the maximum sub array sum present in the array using kadane's algorithm/optimul approach
#include<bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    int maxi=INT_MIN;
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
        sum=sum+nums[i];
        if(sum>maxi)
        {
            maxi=sum;
        }
        else if(sum<0)
        {
            sum=0;
        }
    }
    return maxi;
}
int main()
{
    vector<int> nums={-2,-3,4,-1,-2,1,5,-3};
    cout<<"The maximum subarray sum is: "<<maxSubArray(nums)<<endl;
    return 0;
}