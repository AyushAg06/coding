// find the first and last occurance of an element in a sorted array using binary search
#include<bits/stdc++.h>
using namespace std;
vector<int> Search(vector<int>&nums,int target)
{
    int n=nums.size();
    vector<int>result(2,-1);
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==target)
        {
            result[0]=mid;
            high=mid-1;
        }
        else if(nums[mid]<target)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==target)
        {
            result[1]=mid;
            low=mid+1;
        }
        else if(nums[mid]<target)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return result;
}
int main()
{
    vector<int>nums={1,2,8,10,10,10,12,19};
    int target=10;
    vector<int>result=Search(nums,target);
    cout<<"First Occurance:-"<<result[0]<<endl;
    cout<<"Last Occurance:-"<<result[1]<<endl;
    return 0;
}