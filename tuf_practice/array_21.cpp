// majority element >n/2 times using hashing
#include<bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>&nums)
{
    map<int,int>mpp;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        mpp[nums[i]]++;
    }
    for(auto it: mpp)
    {
        if(it.second>(nums.size()/2))
        {
            return it.first;
        }
    }
    return -1;
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
    cout<<"The majority element is: "<<majorityElement(nums)<<endl;
    return 0;
}