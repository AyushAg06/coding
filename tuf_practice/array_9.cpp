// linear search algorithm
#include<bits/stdc++.h>
using namespace std;
int linearsearch(vector<int>&nums,int target)
{
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==target)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n,target;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<"Enter the element you want to search: "<<endl;
    cin>>target;
    if(linearsearch(nums,target)!=-1)
    {
        cout<<"The element is present at index: "<<linearsearch(nums,target)<<endl;
    }
    else
    {
        cout<<"The element is not present in the array."<<endl;
    }
    return 0;
}