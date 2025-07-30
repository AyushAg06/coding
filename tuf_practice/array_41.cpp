// merge the two sorted array and print the two array in sorted order without using extra space
#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&nums1,vector<int>&nums2)
{
    int n=nums1.size();
    int m=nums2.size();
    int left=n-1;
    int right=0;
    while(left>=0 && right<m)
    {
        if(nums1[left]>nums2[right])
        {
            swap(nums1[left],nums2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());
    for(auto it:nums1)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it:nums2)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int>nums1={1,3,5,7};
    vector<int>nums2={0,2,6,8,9};
    merge(nums1,nums2);
    return 0;
}
// Time complexity: O(nlogn+mlogm)
// Space complexity: O(1)