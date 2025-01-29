// remove duplicates from an array
#include<bits/stdc++.h>
using namespace std;
int removeduplicates(vector<int>&nums)
{
    int i=0;
    for(int j=0;j<nums.size();j++)
    {
        if(nums[j]!=nums[i])
        {
            i++;
            nums[i+1]=nums[j];
        }
    }
    return i+1;
}
int main()
{
    int n;
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<"the size of the array becomes"<<removeduplicates(nums);
    return 0;
}