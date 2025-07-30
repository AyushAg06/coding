// find the maximum subarray sum present in the array better solution
#include<bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    int maxi=INT_MIN;
    for(int i=0;i<nums.size();i++)
    {
        int sum=0;
        for(int j=i;j<nums.size();j++)
        {
            sum=sum+nums[j];
            maxi=max(maxi,sum);
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