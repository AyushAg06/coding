// sum of subarray minimums using brute force approach 
#include<bits/stdc++.h>
using namespace std;
int sumofsubarrayminimum(vector<int>nums)
{
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int mini=nums[i];
        for(int j=i;j<n;j++)
        {
            mini=min(mini,nums[j]);
            sum+=mini;
        }
    }
    return sum;
}
int main()
{
    vector<int>nums={3,1,2,4};
    cout<<"the sum of subarray minimums:-"<<sumofsubarrayminimum(nums);
    return 0;
}