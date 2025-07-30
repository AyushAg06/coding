// find the smallest divisor with a given threshold value
// eg-arr[]={1,2,5,9}, threshold=6
// output=5 as 1/4+2/4+5/4+9/4=2+1+2+3=8>6,1/5+2/5+5/5+9/5=1+1+1+2=5<6
#include<bits/stdc++.h>
using namespace std;
int FindMax(vector<int>&nums)
{
    int maxi=INT_MIN;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,nums[i]);
    }
    return maxi;
}
int SumByDivisor(vector<int>&nums,int mid)
{
    int sum=0;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        sum+=(nums[i]+mid-1)/mid;
    }
    return sum;
}
int SmallestDivisor(vector<int>&nums,int threshold)
{
    int low=1,high=FindMax(nums);
    int ans=-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(SumByDivisor(nums,mid)<=threshold)
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
    vector<int>nums={1,2,5,9};
    int threshold=6;
    cout<<SmallestDivisor(nums,threshold)<<endl;
    return 0;
}
// Time Complexity: O(nlog(max(arr)))
// Space Complexity: O(1)