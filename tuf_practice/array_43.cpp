// print the maximum roduct of the subarray of the given array
#include<bits/stdc++.h>
using namespace std;
int MaxProduct(vector<int>&nums)
{
    int n=nums.size();
    int pre=1,suf=1;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(pre==0)
        {
            pre=1;
        }
        if(suf==0)
    	{
            suf=1;
        }
        pre=pre*nums[i];
        suf=suf*nums[n-i-1];
        maxi=max(maxi,max(pre,suf));
    }
    return maxi;
}
int main()
{
    vector<int>nums={2,3,-2,4};
    cout<<MaxProduct(nums)<<endl;
    return 0;
}
// Time complexity: O(n)
// Space complexity: O(1)   
