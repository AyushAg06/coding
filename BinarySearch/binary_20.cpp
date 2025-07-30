// Find the kth missing positive number using brute force approach
// arr[]={2,3,4,7,11},k=5
// =[1,2.3,4,5,6,7,8,9,10,11] here the fifth missing element is 9
// arr[]={5,7,10},k=4
// =[1,2,3,4,5,6,7,8,9,10] here the fourth missing element is 4
#include<bits/stdc++.h>
using namespace std;
int KthMissingNumber(vector<int>&nums,int k)
{
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        if(nums[i]<=k)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    return k;
}
int main()
{
    vector<int>nums={2,3,4,7,11};
    int k=5;
    cout<<KthMissingNumber(nums,k)<<endl;
    return 0;
}
// time complexity-O(n)
// space complexity-O(1)